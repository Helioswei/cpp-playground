#include "./state.h"
#include "./context.h"

ConcreteStateA* ConcreteStateA::m_state = nullptr;
ConcreteStateA* ConcreteStateA::getInstance()
{
    if (m_state == nullptr)
    {
        m_state = new ConcreteStateA();
    }

    return m_state;

}


void ConcreteStateA::handle(Context* c)
{
    std::cout << "doing someting in StateA, change state to B" << std::endl;
    c ->changeState(ConcreteStateB::getInstance());


}
ConcreteStateB* ConcreteStateB::m_state = nullptr;
ConcreteStateB* ConcreteStateB::getInstance()
{
    if (m_state == nullptr)
    {
        m_state = new ConcreteStateB();
    }

    return m_state;

}


void ConcreteStateB::handle(Context* c)
{
    std::cout << "doing someting in StateB, change state to A" << std::endl;
    c ->changeState(ConcreteStateA::getInstance());

}
