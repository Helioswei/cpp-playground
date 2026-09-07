#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
class Strategy
{
public:
    virtual void algorithm() {}
};

class ConcreteStrategyA : public Strategy
{
public:
    virtual void algorithm()
    {
        std::cout << "ConcreteStrategyA algorithm" << std::endl;
    }

};

class ConcreteStrategyB: public Strategy
{
public:
    virtual void algorithm()
    {
        std::cout << "ConcreteStrategyB algorithm" << std::endl;
    }
};










#endif //STRATEGY_H
