#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
public:
    Product()
{}
    virtual void use() = 0;
    virtual ~Product()
    {}
};



class ProductA : public Product
{

public:
    ProductA()
    {
        std::cout << "ProductA Construct" << std::endl;

    }
    virtual void use()
    {
        std::cout << "ProductA use" << std::endl;

    }
};

class ProductB : public Product
{

public:
    ProductB()
    {
        std::cout << "ProductB Construct" << std::endl;

    }
    virtual void use()
    {

        std::cout << "ProductB use" << std::endl;
    }
};


#endif //PRODUCT_H
