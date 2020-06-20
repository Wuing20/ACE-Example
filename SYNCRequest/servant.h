#ifndef __SERVANT_INCLUDE
#define __SERVANT_INCLUDE

#include "access.idl/Singleton.h"
#include <list>

#define DATA_SIZE 255
#define LIST_SIZE 50

struct STRequest
{
    STRequest& operator=(const STRequest& obj)
    {
        strcpy(_ch,obj._ch);

        return *this;
    }

    char _ch[DATA_SIZE];
};

struct STResponse
{
    STResponse& operator=(const STResponse& obj)
    {
        strcpy(_chResult,obj._chResult);

        return *this;
    }

    char _chResult[DATA_SIZE];
};


class CServantT
{
public:
    friend class ACE_Singleton<CServantT,ACE_Thread_Mutex>;

    void Put(const STRequest &);
    STResponse Get();
    bool Empty();
    bool Full();

private:
    CServantT()
    {}

    ACE_Thread_Mutex _Mutex;
    std::list<STRequest> _lstItems;
};

typedef ACE_Singletion<CServantT,ACE_Thread_Mutex> CServant;

#endif