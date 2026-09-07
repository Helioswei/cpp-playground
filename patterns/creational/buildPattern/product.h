#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>


class Product
{
public:
    void setA()
    {
        std::cout << "Product setA" << std::endl;
    };
    void setB()
    {
        std::cout << "Product setB" << std::endl;
    };
    void setC()
    {
        std::cout << "Product setC" << std::endl;
    };
    void setD()
    {
        std::cout << "Product setD" << std::endl;
    };
    void show()
    {
        std::cout << "Product show" << std::endl;
    }
};





#endif //PRODUCT_H
