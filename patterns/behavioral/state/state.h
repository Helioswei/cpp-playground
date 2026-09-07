#ifndef STATE_H
#define STATE_H
#include <iostream>
class Context;
class State
{
public:
    virtual ~State() {}
    virtual void handle(Context* c) {}

};

class ConcreteStateA: public State
{
public:
    virtual ~ConcreteStateA()
    {
        delete m_state;
    }
    static ConcreteStateA* getInstance();
    virtual void handle(Context* c);
private:
    ConcreteStateA() {}
    static  ConcreteStateA* m_state;
};


class ConcreteStateB: public State
{
public:
    virtual ~ConcreteStateB()
    {
        delete m_state;
    }
    static ConcreteStateB* getInstance();
    virtual void handle(Context* c);
private:
    ConcreteStateB() {}
    static  ConcreteStateB* m_state;
};


#endif //STATE_H
