#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
class AbstractClass
{
    public:
        virtual ~AbstractClass(){}
        virtual void primitive1(){}
};

class ConcreteClassA : public AbstractClass
{
    public:
        ConcreteClassA(){}
        ~ConcreteClassA(){}
        virtual void primitive1()
        {
            std::cout << "primitive1" << std::endl;
        }
};


class ConcreteClassB : public AbstractClass
{
    public:
        ConcreteClassB(){}
        ~ConcreteClassB(){}
        virtual void primitive1()
        {
            std::cout << "ConcreteClassB primitive1" << std::endl;
        }
};








#endif // TEMPLATE_H
