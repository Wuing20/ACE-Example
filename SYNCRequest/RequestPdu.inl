template <typename ITEM>
void CRequestPdu<ITEM>::Call()
{
    CServant::instance()->Put(_Item);
}

template <typename ITEM>
bool CRequestPdu<ITEM>::Guard() const
{
    return !CServant::instance()->Full();
}