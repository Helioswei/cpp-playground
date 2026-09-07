#ifndef ORIGINATOR_H
#define ORIGINATOR_H
#include "./memento.h"
#include <iostream>
//原发器
class Originator
{
public:
    Originator():m_mt(nullptr),m_state("begin") {}
    Originator(const std::string& state): m_mt(nullptr),m_state(state) {}
    ~Originator() {}
    Memento* createMemento() {
        return new Memento(m_state);
    }
    void restoreToMemento(Memento* mt) {
        m_state = mt->m_state;
    }
    std::string getState()
    {

        return m_state;
    }
    void setState(const std::string& state)
    {
        m_state = state;
    }
    void printState()
    {

        std::cout << "current m_state is " << m_state << std::endl;
    }
private:
    std::string m_state;//存储状态
    Memento* m_mt;//备忘录
};

#endif //ORIGINATOR_H
