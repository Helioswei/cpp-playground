#include "flyweightFactory.h"
int main(int argc , char* argv[])
{
    std::string str = "wei";
    FlyWeightFactory factory;
    FlyWeight* flyWeight = factory.getFlyweight(str);
    flyWeight->operation();

    return 0;


}
