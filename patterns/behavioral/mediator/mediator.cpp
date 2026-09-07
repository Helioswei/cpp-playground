#include "./mediator.h"
#include "./colleague.h"

void ConcreteMediator::doActionFromAToB()
{
        m_clgB->setState(m_clgA->getState());

}
void ConcreteMediator::doActionFromBToA()
{
        m_clgA->setState(m_clgB->getState());

}
