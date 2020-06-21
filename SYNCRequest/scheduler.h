#ifndef __SCHEDULER_INCLUDE
#define __SCHEDULER_INCLUDE

#include "pdu.h"
#include "ace/Task_Ex_T.h"


class CScheduler : public ACE_Task_Ex<ACE_MT_SYNCH,CPduBase>
{
public:
    int open(void *);
    int svc(void);
    int SetExit();
};



#endif
