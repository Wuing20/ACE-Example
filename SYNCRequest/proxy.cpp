#include "proxy.h"
#include "scheduler.h"

#ifdef TIMEOUT
#undef TIMEOUT
#define TIMEOUT 20
#else
#define TIMEOUT 20
#endif

CResponsePdu<STResponse>* CProxy::Call(const STRequest& obj)
{
    CRequestPdu<STRequest>* pRequest = new
                                        CRequestPdu<STRequest>(obj);
    CResponsePdu<STResponse>* pResp = new
                                        CResponsePdu<STResponse>(TIMEOUT);

    ACE_Guard<ACE_Thread_Mutex> guard(_Mutex);
    _pScheduler->putq(pRequest);
    pResp->AddRef();
    _pScheduler->putq(pResp);

    return pResp;
}
