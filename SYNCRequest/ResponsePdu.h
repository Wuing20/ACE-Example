#ifndef __RESPONSE_PDU_INCLUDE
#define __RESPONSE_PDU_INCLUDE

#include "pdu.h"

template <typename ITEM>
class CResponsePdu : public CPduBase
{
public:
    CResponsePdu(int nTimeout) 
        : _nTimeout(nTimeout)
          _semLock(0)
    {}

    operator ITEM() throw(CPduException);
    bool Guard() const;
    void Call();

private:
    int _nTimeout;
    ACE_Semaphore _semLock;
    ITEM _Item;
};


#include "ResponsePdu.inl"

#endif