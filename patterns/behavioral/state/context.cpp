#include "./context.h"
#include "./state.h"

Context::Context()
{
    m_state = ConcreteStateA::getInstance();

}
void Context::changeState(State* state)
{
    m_state = state;
}

void Context::request()
{
    m_state ->handle(this);

}
