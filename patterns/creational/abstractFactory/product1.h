#ifndef PRODUCT1_H
#define PRODUCT1_H
#include <iostream>

class ProductIcebox
{
public:
    ProductIcebox()
    {}
    virtual void use() = 0;
    virtual ~ProductIcebox()
    {}
};



class ProductHaierIcebox : public ProductIcebox
{

public:
    ProductHaierIcebox()
    {
        std::cout << "ProductHaierIcebox Construct" << std::endl;

    }
    virtual void use()
    {
        std::cout << "ProductHaierIcebox use" << std::endl;

    }
};

class ProductMeideIcebox : public ProductIcebox
{

public:
    ProductMeideIcebox()
    {
        std::cout << "ProductMeideIcebox Construct" << std::endl;

    }
    virtual void use()
    {

        std::cout << "ProductMeideIcebox use" << std::endl;
    }
};


#endif //PRODUCT1_H
