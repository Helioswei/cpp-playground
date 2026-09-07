#include "template.h"
//模板模式
int main(int argc , char* argv[])
{
    AbstractClass* ab = new ConcreteClassB();
    AbstractClass* ab1 = new ConcreteClassA();
    ab->primitive1();
    ab1->primitive1();
    delete ab, ab1;
    return 0;


}
