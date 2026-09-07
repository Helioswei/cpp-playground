#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>

//抽象主题角色
class Subject
{
public:
    Subject() {}
    virtual ~Subject() {}

    virtual void request()
    {}


};

//真实主题角色
class RealSubject : public Subject
{
public:
    RealSubject() {}
    ~RealSubject() {}
    virtual void request()
    {
        std::cout << "RealSubject request" << std::endl;

    }
};

//代理主题角色
class Proxy : public Subject
{
public:
    Proxy()
    {
        m_sub = new RealSubject();

    }
    ~Proxy()
    {

        delete m_sub;
    }
    virtual void request()
    {
        m_sub -> request();
    }
private:
    void preRequest()
    {
        std::cout << "Proxy preRequest" << std::endl;
    }
    void afterRequest()
    {
        std::cout << "Proxy afterRequest" << std::endl;
    }
    RealSubject* m_sub;

};


#endif //SUBJECT_H
