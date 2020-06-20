#ifndef __REQUEST_PDU_INCLUDE
#define __REQUEST_PDU_INCLUDE

#include "pdu.h"

template <typename ITEM>
class CRequestPdu : public CPduBase
{
public:
    CRequestPdu(const ITEM& item) : _Item(item)
    {}
    bool Guard() const;
    void Call();

private:
    ITEM _Item;
};

#include "RequestPdu.inl"

#endif