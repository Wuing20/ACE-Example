#ifndef __PDU_INCLUDE
#define __PDU_INCLUDE

#include "ace/Semaphore.h"
#include "ace/Atomic_Op.h"
#include "servant.h"

class CPduException
{
public:
    CPduException(int n) : _Err(n)
    {
    }

    int _Err;
};

class CPduBase
{
public:
    CPduBase : _nRef(1)
    {}

    virtual bool Guard() const = 0;
    virtual void Call() = 0;
    void AddRef()
    {
        _nRef++;
    }

    void Release()
    {
        _nRef--;

        if(0 == _nRef.value())
        {
            delete this;
        }
    }

private:
    ACE_Atomic_Op<ACE_Thread_Mutex,long> _nRef;
};

#endif