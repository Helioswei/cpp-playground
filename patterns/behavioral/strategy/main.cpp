#include "context.h"
//策略模式
int main(int argc , char* argv[])
{
    Context* c = new Context();
    c->setStrategy(new ConcreteStrategyA());
    c->algorithm();
    c->setStrategy(new ConcreteStrategyB());
    c->algorithm();
    delete c;



    return 0;


}
