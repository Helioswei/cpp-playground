#ifndef ABSTRACTIONIMP_H
#define ABSTRACTIONIMP_H
#include <iostream>


class AbstractionImp
{
public:
    virtual ~AbstractionImp() {}
    virtual void operation() {}
};

class AbstractionImp1 : public AbstractionImp
{
public:
    ~AbstractionImp1(){}
    virtual void operation()
    {
        std::cout << "AbstractionImp1 operation" << std::endl;
    }

};

class AbstractionImp2 : public AbstractionImp
{
public:
    ~AbstractionImp2(){}
    virtual void operation()
    {
        std::cout << "AbstractionImp2 operation" << std::endl;
    }
};

#endif //ABSTRACTIONIMP_H
