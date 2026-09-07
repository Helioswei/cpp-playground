#ifndef ABSTRACTION_H
#define ABSTRACTION_H
#include "abstractionImp.h"

class Abstraction
{
public:
    virtual ~Abstraction() {}
    virtual void operation() {}
};

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(AbstractionImp* imp): m_imple(imp) {}
    ~RefinedAbstraction() {}
    virtual void operation()
    {
        m_imple ->operation();

    }
private:
    AbstractionImp* m_imple;
};

#endif //ABSTRACTION_H
