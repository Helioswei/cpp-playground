#ifndef COLLEAGE_H
#define COLLEAGE_H
#include "mediator.h"

class Colleage
{
public:
    Colleage() {}
    virtual ~Colleage() {}
    virtual void action() {}
    virtual void setState(const std::string& msg) {}
    virtual std::string getState()
    {
        return {};
    }
protected:
    Colleage(Mediator* mediator): m_mediator(mediator)
    {}
    Mediator* m_mediator;
};

class ColleageA : public Colleage
{
public:
    ColleageA(){}
    ColleageA(Mediator* mediaotr): Colleage(mediaotr) {}
    ~ColleageA() {}
    virtual void action()
    {
        std::cout << "ColleageA action" << std::endl;
        m_mediator->doActionFromAToB();
    }
    virtual void setState(const std::string& msg)
    {
        m_str = msg;
    }
    virtual std::string getState()
    {
        return m_str;
    }

private:
    std::string m_str;

};

class ColleageB : public Colleage
{
public:
    ColleageB(){}
    ColleageB(Mediator* mediaotr): Colleage(mediaotr) {}
    ~ColleageB() {}
    virtual void action()
    {
        std::cout << "ColleageB action" << std::endl;
        m_mediator->doActionFromBToA();
    }
    virtual void setState(const std::string& msg)
    {
        m_str = msg;
    }
    virtual std::string getState()
    {
        return m_str;
    }

private:
    std::string m_str;

};


#endif //COLLEAGE_H
