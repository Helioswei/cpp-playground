#include "factory.h"
int main(int argc , char* argv[])
{

    //创建海尔工厂
    Factory* factory = new FactoryHaier();
    //生产海尔电视
    ProductTV* product = factory -> CreateTV();
    //生产海尔冰箱
    ProductIcebox* iceBox = factory->CreateIceBox();
    product->use();
    iceBox->use();

    //创建美的工厂
    Factory* meiDe = new FactoryMeide();
    //创建美的电视
    ProductTV* meiDeTv = meiDe->CreateTV();
    //创建美的冰箱
    ProductIcebox* meiDeIce = meiDe->CreateIceBox();
    meiDeTv->use();
    meiDeIce->use();


    delete factory;
    delete product;
    delete iceBox;

    delete meiDe;
    delete meiDeTv;
    delete meiDeIce;
    return 0;

}
