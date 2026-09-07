#ifndef BUILD_H
#define BUILD_H
#include <iostream>
#include "./product.h"

class AbstractBuild
{
public:
    virtual ~AbstractBuild() {}
    virtual void buildPartA() {};
    virtual void buildPartB() {};
    virtual void buildPartC() {};
    virtual void buildPartD() {};
    virtual Product* getResult() {};
};

class Builder : public AbstractBuild
{
public:
    Builder()
    {
        m_product = new Product;
    }
    ~Builder() {}
    virtual void buildPartA()
    {
        std::cout << "build Part A" << std::endl;
        m_product->setA();
    };
    virtual void buildPartB()
    {
        std::cout << "build Part B" << std::endl;
        m_product->setB();
    };
    virtual void buildPartC()
    {
        std::cout << "build Part C" << std::endl;
        m_product->setC();
    };
    virtual void buildPartD()
    {
        std::cout << "build Part D" << std::endl;
        m_product->setD();
    };
    Product* getResult()
    {
        return m_product;
    };
private:
    Product* m_product;
};

#endif //BUILD_H
