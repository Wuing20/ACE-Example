#ifndef __CLIENT_INCLUDE
#define __CLIENT_INCLUDE

#include "ace/ACE.h"
#include "proxy.h"
#include "scheduler.h"

class CClient : public ACE_Task<ACE_MT_SYNCH>
{
public:
    CClient(CProxy* proxy);

    int open(void *);
    int svc(void);
    void SetExit();

private:
    bool _bRun;
    CProxy* _Proxy;
};


#endif
