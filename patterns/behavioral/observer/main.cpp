#include "subject.h"
int main(int argc , char* argv[])
{
    Observer *observer1 = new ConcreteObserver();
    Observer *observer2 = new ConcreteObserver();
    Observer *observer3 = new ConcreteObserver();

    Subject * sub = static_cast<Subject*>(new ConcreteSubject());
    sub ->attach(observer1); 
    sub ->attach(observer1); 
    sub ->attach(observer2); 
    sub ->attach(observer3); 
    sub->notify();
    std::cout << "set: " << std::endl;
    sub->setState(1);
    sub->notify();



    return 0;


}
