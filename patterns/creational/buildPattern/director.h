#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "./build.h"

class Director
{
private:
    AbstractBuild* m_build;
public:
    Product* construct()
    {
        m_build ->buildPartA();
        m_build ->buildPartB();
        m_build ->buildPartC();
        m_build ->buildPartD();
        return m_build->getResult();
    }
    void setBuild(AbstractBuild* build)
    {
        m_build = build;
    }
};

#endif //DIRECTOR_H
