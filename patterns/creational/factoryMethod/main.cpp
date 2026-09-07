#include "factory.h"
int main(int argc , char* argv[])
{

    //创建对应的工厂
    Factory* factoryA = new FactoryA();
    Product* productA = factoryA->factoryMethod();
    productA->use();

    Factory* factoryB = new FactoryB();
    Product* productB = factoryB->factoryMethod();
    productB->use();

    delete factoryA;
    delete productA;
    delete factoryB;
    delete productB;


    return 0;


}
