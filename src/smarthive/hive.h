// Copyright (c) 2018 dustinface - SmartCash Developer
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef HIVE_H
#define HIVE_H

#include "amount.h"
#include "chain.h"
#include "coins.h"
#include "base58.h"

struct CSmartAddress : public CBitcoinAddress
{
    ADD_SERIALIZE_METHODS

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion) {
        READWRITE(vchVersion);
        READWRITE(vchData);
    }

    CSmartAddress() : CBitcoinAddress() {}
    CSmartAddress(const std::string &address) : CBitcoinAddress(address) {}
    CSmartAddress(const CTxDestination &destination) : CBitcoinAddress(destination) {}
    CSmartAddress(const char* pszAddress) : CBitcoinAddress(pszAddress) {}

    int Compare(const CSmartAddress& other) const
    {
        std::vector<unsigned char> aVec = vchVersion;
        aVec.insert(aVec.end(), vchData.begin(), vchData.end());

        std::vector<unsigned char> bVec = other.vchVersion;
        bVec.insert(bVec.end(), other.vchData.begin(), other.vchData.end());

        return memcmp(aVec.data(), bVec.data(), aVec.capacity());
    }

    CScript GetScript() const { return GetScriptForDestination(Get()); }
};

namespace SmartHive{

    enum Payee{
        Development,
        Outreach,
        Support,
        SmartRewards, //Deprecated with 1.2
        ProjectTreasury,
        Outreach2,
        Web,
        Quality
    };

    const CScript* ScriptPtr(SmartHive::Payee payee);
    inline const CScript& Script(SmartHive::Payee payee){return *ScriptPtr(payee);}
    const CSmartAddress& Address(SmartHive::Payee payee);

    void Init();
    inline bool Is(SmartHive::Payee payee, const CScript &script){ return Script(payee) == script; }
    bool IsHive(const CSmartAddress &address);
    bool IsHive(const CScript &script);

}

#endif // HIVE_H
