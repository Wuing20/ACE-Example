#ifndef __SCHEDULER_INCLUDE
#define __SCHEDULER_INCLUDE

#include "pdu.h"
#include "ace/Tack_Ex_T.h"


class CScheduler : public ACE_Tack_Ex<ACE_MT_SYNCH,CPduBase>
{
public:
    int open(void *);
    int svc(void);
    int SetExit();
}



#endif