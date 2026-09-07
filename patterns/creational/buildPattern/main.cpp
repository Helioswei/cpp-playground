#include "director.h"
int main(int argc , char* argv[])
{
    Builder* builder = new Builder();

    //指挥者
    Director director;
    director.setBuild(static_cast<AbstractBuild*>(builder));
    Product* product = director.construct();
    product->show();

    delete builder;
    delete product;

    return 0;
}
