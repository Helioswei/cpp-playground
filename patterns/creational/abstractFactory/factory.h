#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
#include "./product.h"
#include "./product1.h"

class Factory
{
public:
    virtual ~Factory() {};
    virtual ProductTV*  CreateTV()
    {
        return nullptr;
    }
    virtual ProductIcebox* CreateIceBox()
    {
        return nullptr;

    }
};

class FactoryHaier : public Factory
{
public:
    virtual ProductTV* CreateTV()
    {
        ProductTV* product = static_cast<ProductTV*>(new ProductHaierTV);
        return product;
    }
    virtual ProductIcebox* CreateIceBox()
    {
        ProductIcebox* product = static_cast<ProductIcebox*>(new ProductHaierIcebox);
        return product;
    }
};

class FactoryMeide : public Factory
{
public:
    virtual ProductTV* CreateTV()
    {
        ProductTV* product = static_cast<ProductTV*>(new ProductMeideTV);
        return product;
    }
    virtual ProductIcebox* CreateIceBox()
    {
        ProductIcebox* product = static_cast<ProductIcebox*>(new ProductMeideIcebox);
        return product;
    }
};
#endif //FACTORY_H
