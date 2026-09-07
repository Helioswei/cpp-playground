#ifndef CONTEXT_H
#define CONTEXT_H
#include <iostream>
#include "./strategy.h"

class Context
{
public:
    Context(){}
    ~Context(){}
    void algorithm()
    {
        m_strate->algorithm();

    }
    void setStrategy(Strategy* strate)
    {
        m_strate = strate;
    }
private:
    Strategy* m_strate;
};

#endif //CONTEXT_H
