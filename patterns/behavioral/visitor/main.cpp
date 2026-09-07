#include "context.h"
//访问模式
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
