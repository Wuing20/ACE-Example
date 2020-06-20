template <typename ITEM>
void CResponsePdu<ITEM>::Call()
{
    _Item = CServant::instance()->Get();
    _semLock.release();
}

template <typename ITEM>
bool CResponsePdu<ITEM>::Guard() const
{
    return !CServant::instance()->Empty();
}

template <typename ITEM>
CResponsePdu<ITEM>::operator ITEM()
throw(CPduException)
{
    ACE_Time_Value t(_nTimeout,0);

    if(-1 == _semLock.acquire(t))
    {
        throw CPduException(ETIME);
    }

    return _Item;
}