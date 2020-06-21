#include "Client.h"

CClient::CClient(CProxy* proxy)
    : _Proxy(proxy),_bRun(0)
{

}


int CClient::open(void *)
{
    activate(THR_NEW_LWP,8);
    _bRun = 1;

    return 0;
}

int CClient::svc(void)
{
    STRequest obj;
    long n = 0;

    while(_bRun)
    {
        sprintf(obj._ch,"client: %d, %d request\n",ACE_Thread::self(),n++);

        try{
            CResponsePdu<STResponse>* pResp = _Proxy->Call(obj);
            STResponse tResp = *pResp;

            if(0 != strcmp(obj._ch,tResp._chResult))
            {
                ACE_DEBUG((LM_DEBUG,"req and res not samiler: %s",tResp._chResult));
                pResp->Release();
            }
		}
        catch(CPduException &e){

        }

		ACE_OS::sleep(1); 
    }

    return 0;
}

void CClient::SetExit()
{
    _bRun = 0;
    wait();
}
