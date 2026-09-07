#ifndef FACADE_H
#define FACADE_H
#include <iostream>
#include "system.h"

class Facade
{
public:
    Facade()
    {
        m_sysA = new SystemA;
        m_sysB = new SystemB;
        m_sysC = new SystemC;
    }
    ~Facade()
    {
        delete m_sysA;
        delete m_sysB;
        delete m_sysC;

    };
    void wrapOperation()
    {
        m_sysA ->operationA();
        m_sysB ->operationB();
        m_sysC ->operationC();
    }
private:
    SystemA* m_sysA;
    SystemB* m_sysB;
    SystemC* m_sysC;
};













#endif //FACADE_H
