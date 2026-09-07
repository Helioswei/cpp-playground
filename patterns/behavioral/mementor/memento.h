#ifndef MEMENTO_H
#define MEMENTO_H
#include <iostream>
class Originator;
class Memento
{
public:
protected:
private:
    Memento() {}
    Memento(const std::string& state)
    {
        m_state = state;
    }
    ~Memento() {}
    void setState(const std::string& state)
    {
        m_state = state;
    }
    std::string getState()
    {
        return m_state;
    }
private:
    /*
     * 这里是关键，将Originator设置为friend类，可以访问内部信息，但是其他的类
     * 不能访问
     * */
    friend class Originator;
    std::string m_state;
};









#endif //MEMENTO_H
