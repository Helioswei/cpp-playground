#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <iostream>

class Colleage;
class Mediator
{
public:
    Mediator() {}
    virtual ~Mediator() {}
    virtual void introColleage() {}
    virtual void doActionFromAToB() {}
    virtual void doActionFromBToA() {}
};

class ConcreteMediator: public Mediator
{
public:
    ConcreteMediator(Colleage* clgA, Colleage* clgB): m_clgA(clgA), m_clgB(clgB) {}
    ~ConcreteMediator() {}
    virtual void introColleage() {}
    virtual void doActionFromAToB();
    virtual void doActionFromBToA();
private:
    Colleage* m_clgA;
    Colleage* m_clgB;
};




#endif //MEDIATOR_H
