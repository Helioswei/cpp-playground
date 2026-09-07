#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H
#include <iostream>

class FlyWeight
{

public:
    FlyWeight() {}
    virtual ~FlyWeight() {}
    virtual void operation() {}
};

class ConcreteFlyWeight : public FlyWeight
{
public:
    ConcreteFlyWeight(std::string state): m_intriState(state) {}
    virtual ~ConcreteFlyWeight() {}
    virtual void operation()
    {
        std::cout << "ConcreteFlyWeight operation state : " << m_intriState  << std::endl;

    }
private:
    std::string m_intriState;


};

class UnsharedConcreteFlyWeight: public FlyWeight
{};











#endif //FLYWEIGHT_H
