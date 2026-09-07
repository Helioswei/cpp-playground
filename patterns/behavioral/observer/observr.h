#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>

class Observer
{
    public:
        virtual ~Observer(){}
        virtual void update(int i){}
};

class ConcreteObserver : public Observer
{
    public:
        ConcreteObserver():m_state(0){}
        ~ConcreteObserver(){}
        virtual void update(int i)
        {
            m_state = i;
            std::cout << "Observer address: " << this << " m_state: " << m_state << std::endl;
        }
    private:
        int m_state; //0,1
};

#endif //OBSERVER_H
