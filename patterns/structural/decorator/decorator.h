#ifndef DECORATOR_H
#define DECORATOR_H
#include "./component.h"

class Decorator : public Component
{
public :
    Decorator(Component* comm): m_comm(comm) {}
    virtual ~Decorator()
    {
        delete m_comm;
    }
    virtual void operation()
    {
    }
protected:
    Component* m_comm;

};

class ConcreteDecorator : public Decorator
{
public :
    ConcreteDecorator(Component* comm): Decorator(comm) {}
    ~ConcreteDecorator() {}
    void addbehavior()
    {
        std::cout << "ConcreteDecorator addbehavior" << std::endl;
    }
    void operation()
    {
        m_comm->operation();
        addbehavior();
    }
};










#endif //DECORATOR_H
