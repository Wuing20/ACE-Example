#ifndef __PROXY_INCLUDE
#define __PROXY_INCLUDE

#include "servant.h"
#include "ResponsePdu.h"
#include "RequestPdu.h"

class CScheduler;

class CProxy
{
public:
    CProxy(CScheduler* p) : _pScheduler(p)
    {}

    CResponsePdu<STResponse>* Call(const STRequest& obj);

private:
    ACE_Thread_Mutex _Mutex;
    CScheduler* _pScheduler;
};


#endif
