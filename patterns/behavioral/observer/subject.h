#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "observr.h"


class Subject
{
    public:
        virtual ~Subject(){}
        virtual void attach(Observer* observer){
            auto it = std::find(m_observers.begin(), m_observers.end(), observer);
            if(it != m_observers.end())
            {
                std::cout << "Current observer is exists,address is " << observer << std::endl;
            }
            else
            {
                m_observers.push_back(observer);
            }
        }
        virtual void detach(Observer* observer){
            auto it = std::find(m_observers.begin(), m_observers.end(), observer);
            if(it != m_observers.end())
            {
                m_observers.erase(it);
            }
            else
            {
                std::cout << "Current observer is not exists,please add" << std::endl;
            }
        
        }
        virtual void notify(){
            for(auto observer : m_observers)
            {
                observer->update(m_state);
            }
        }
        virtual void  setState(int state){}
        //void setState(int state){ m_state = state;};
    protected:
        std::vector<Observer*> m_observers;
        int m_state;

};

class ConcreteSubject : public Subject
{
    public:
        ConcreteSubject(){}
        ~ConcreteSubject(){}
        void setState(int state){ m_state = state;};
};
















#endif //SUBJECT_H
