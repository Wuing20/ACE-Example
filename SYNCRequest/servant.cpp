#include "servant.h"

void CServantT::Put(const STRequest& item)
{
    ACE_Guard<ACE_Thread_Mutex> guard(_Mutex);
    this->_lstItems.push_back(item);
}

STResponse CServantT::Get()
{
    STResponse req;

    ACE_Guard<ACE_Thread_Mutex> guard(_Mutex);
    STRequest item = *(this->_lstItems.begin());

    strcpy(req._chResult,item._ch);
    this->_lstItems.pop_front();

    return req;
}

bool CServantT::Empty()
{
    return this->_lstItems.empty();
}

bool CServantT::Full()
{
    return this->_lstItems.size() >= LIST_SIZE;
}