#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
#include "./product.h"

class Factory
{
public:
    virtual ~Factory() {};
    virtual Product*  factoryMethod()
    {
        return nullptr;
    };
};

class FactoryA : public Factory
{
public:
    virtual Product* factoryMethod()
    {
        Product* product = static_cast<Product*>(new ProductA);
        return product;
    }
};

class FactoryB : public Factory
{
public:
    virtual Product* factoryMethod()
    {
        Product* product = static_cast<Product*>(new ProductB);
        return product;
    }
};
#endif //FACTORY_H
