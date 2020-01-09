#include "scheme_uncleHeader.h"
using namespace test;

string const emptyString;
scheme_uncleHeader::scheme_uncleHeader(DataObject const& _data) : object(_data)
{
    requireJsonFields(_data, "blockchainTest::uncleblockHeader",
        {{"populateFromBlock", {{DataType::String}, jsonField::Required}},
            {"overwriteAndRedoPoW", {{DataType::String}, jsonField::Optional}},
            {"bloom", {{DataType::String}, jsonField::Optional}},
            {"coinbase", {{DataType::String}, jsonField::Optional}},
            {"difficulty", {{DataType::String}, jsonField::Optional}},
            {"extraData", {{DataType::String}, jsonField::Optional}},
            {"gasLimit", {{DataType::String}, jsonField::Optional}},
            {"gasUsed", {{DataType::String}, jsonField::Optional}},
            {"hash", {{DataType::String}, jsonField::Optional}},
            {"mixHash", {{DataType::String}, jsonField::Optional}},
            {"nonce", {{DataType::String}, jsonField::Optional}},
            {"number", {{DataType::String}, jsonField::Optional}},
            {"parentHash", {{DataType::String}, jsonField::Optional}},
            {"receiptTrie", {{DataType::String}, jsonField::Optional}},
            {"stateRoot", {{DataType::String}, jsonField::Optional}},
            {"timestamp", {{DataType::String}, jsonField::Optional}},
            {"transactionsTrie", {{DataType::String}, jsonField::Optional}},
            {"RelTimestampFromPopulateBlock", {{DataType::String}, jsonField::Optional}},
            {"uncleHash", {{DataType::String}, jsonField::Optional}}});
}

string const& scheme_uncleHeader::getRelTimestampFromPopulateBlock() const
{
    if (m_data.count("RelTimestampFromPopulateBlock"))
        return m_data.atKey("RelTimestampFromPopulateBlock").asString();
    return emptyString;
}

size_t scheme_uncleHeader::getPopulateFrom() const
{
    return (size_t)atoi(m_data.atKey("populateFromBlock").asString().c_str());
}

string const& scheme_uncleHeader::getOverwrite() const
{
    if (m_data.count("overwriteAndRedoPoW"))
        return m_data.atKey("overwriteAndRedoPoW").asString();
    return emptyString;
}