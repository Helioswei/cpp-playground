#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class ProductTV
{
public:
    ProductTV()
    {}
    virtual void use() = 0;
    virtual ~ProductTV()
    {}
};



class ProductHaierTV : public ProductTV
{

public:
    ProductHaierTV()
    {
        std::cout << "ProductHaierTV Construct" << std::endl;

    }
    virtual void use()
    {
        std::cout << "ProductHaierTV use" << std::endl;

    }
};

class ProductMeideTV : public ProductTV
{

public:
    ProductMeideTV()
    {
        std::cout << "ProductMeideTV Construct" << std::endl;

    }
    virtual void use()
    {

        std::cout << "ProductMeideTV use" << std::endl;
    }
};


#endif //PRODUCT_H
