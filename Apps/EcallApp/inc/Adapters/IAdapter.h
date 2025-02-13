#ifndef _IADAPTER_H 
#define _IADAPTER_H
class IAdapter
{
public:
    IAdapter(){}; 
    virtual ~IAdapter(){}; 
    virtual void registerService() = 0;
};

#endif /* _IADAPTER_H */