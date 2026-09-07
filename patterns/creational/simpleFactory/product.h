
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
public:
    //Product();
    virtual void use() = 0;
};



class ProductA : public Product
{

public:
    ProductA();
    virtual void use() ;
};
ProductA::ProductA()
{
    std::cout << "ProductA Construct" << std::endl;
}
void ProductA::use()
{
    std::cout << "ProductA" << std::endl;
}

class ProductB : public Product
{

public:
    ProductB();
    virtual void use();
};
ProductB::ProductB()
{
    std::cout << "ProductB Construct" << std::endl;
}
void ProductB::use()
{
    std::cout << "ProductB" << std::endl;
}


class Factory
{
public:
    Factory();
    virtual ~Factory();
    static Product* getProduct(const std::string& type);
};

Product* Factory::getProduct(const std::string& type)
{
    if (type == "A")
    {
        ProductA* a = new ProductA();
        return a;
    }
    else if (type == "B")
    {

        ProductB* b = new ProductB();
        return b;
    }

}

#endif //PRODUCT_H
