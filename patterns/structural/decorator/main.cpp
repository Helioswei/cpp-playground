#include "decorator.h"
int main(int argc , char* argv[])
{
    Component* comm = new ConcreteComponent();

    Decorator* dec = new ConcreteDecorator(comm);
    dec ->operation();
    return 0;


}
