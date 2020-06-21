#include "scheduler.h"

#define THREAD_NUMS 10

int CScheduler::open(void *)
{
    activate(THR_NEW_LWP,1);

    return 0;
}

int CScheduler::svc(void)
{
    CPduBase* pPdu = NULL;

    while(1)
    {
        getq(pPdu);

        if((CPduBase *)-1 == pPdu)
        {
            break;
        }

        if(pPdu->Guard())
        {
            pPdu->Call();
        }

        pPdu->Release();
		ACE_OS::sleep(1);
    }

    return 0;
}

int CScheduler::SetExit()
{
    for(int i = 0; i < THREAD_NUMS; ++i)
    {
        putq((CPduBase *)-1);
    }
    wait();

    return 0;
}
