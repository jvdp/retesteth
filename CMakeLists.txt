
cmake_minimum_required(VERSION 3.9.3)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)

include("./cmake/Hunter/HunterGate.cmake")

set(HUNTER_CONFIGURATION_TYPES Release)
set(HUNTER_JOBS_NUMBER 4 CACHE STRING "Hunter jobs number")
set(HUNTER_CACHE_SERVERS "https://github.com/ethereum/hunter-cache" CACHE STRING "Hunter cache servers")

HunterGate(
	URL "https://github.com/jvdp/hunter/archive/refs/heads/master.tar.gz"
	SHA1 "13f3a374e0c472a34f1d7e9a1053b22ac936d26b"
	LOCAL
)

project(retesteth VERSION 0.1.0)
set(VERSION_SUFFIX "accesslist")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
hunter_add_package(Boost COMPONENTS filesystem program_options system)
find_package(Boost CONFIG REQUIRED filesystem program_options system)

hunter_add_package(yaml-cpp)
find_package(yaml-cpp CONFIG REQUIRED)
hunter_add_package(cryptopp)
find_package(cryptopp CONFIG REQUIRED)
hunter_add_package(libscrypt)
find_package(libscrypt CONFIG REQUIRED)
hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)


#Cmake files configuration
set(ETH_CMAKE_DIR "${CMAKE_CURRENT_LIST_DIR}/cmake" CACHE PATH "The path to the cmake directory")
list(APPEND CMAKE_MODULE_PATH ${ETH_CMAKE_DIR})
include(EthOptions)
include(EthDependencies)
include(EthCompilerSettings)

include(ProjectSecp256k1)
include(ProjectLibFF)
configure_project()

if(JSONCPP)
    hunter_add_package(jsoncpp)
    find_package(jsoncpp CONFIG REQUIRED)
endif()

add_subdirectory(libdevcore)
add_subdirectory(libdevcrypto)
add_subdirectory(retesteth)

