#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>

class Component
{
public:
    Component() {}
    virtual ~Component() {}
    virtual void operation()
    {}
};

class ConcreteComponent : public Component
{
public:
    ConcreteComponent() {}
    ~ConcreteComponent() {}
    virtual void operation()
    {
        std::cout << "ConcreteComponent operation" << std::endl;

    }
};


















#endif //COMPONENT_H
