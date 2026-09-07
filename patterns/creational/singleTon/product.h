#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
public:
   static Product* getInstance()
    {
        if (m_product == nullptr)
        {
            m_product = new Product();
        }
        return m_product;
    }

    void show()
    {
        std::cout << "Product show" << std::endl;
    }
private:
    Product()
    {
        std::cout << "Prodect construct" << std::endl;
    }

    ~Product()
    {
        std::cout << "Prodect ~construct" << std::endl;
        if (m_product != nullptr)
        {
            delete m_product;
        }
    }

    static Product* m_product;
};
Product* Product::m_product = nullptr;


#endif //PRODUCT_H
