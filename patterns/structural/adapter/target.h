#ifndef TARGET_H
#define TARGET_H
/*加入用户需要调用的是Target类中的request接口
*但是，我们实现的接口是Adaptee中的specificRequest接口
*这是我们在中间添加一个适配器类Adapter来调用Adaptee中的接口就好了
*/
#include <iostream>

class Target
{
public:
    Target() {}
    virtual ~Target() {}
    virtual void request()
    {
        std::cout << "Target request" << std::endl;

    };

};




class Adaptee
{

public:
    Adaptee() {}
    ~Adaptee() {}
    void specificRequest()
    {
        std::cout << "Adaptee specificRequest" << std::endl;
    }

};



/*
 * @brief: 对象适配
 */
class Adapter : public Target
{
public:
    Adapter(Adaptee* adaptee): m_adaptee(adaptee) {}
    ~Adapter() {}
    virtual void request()
    {
        m_adaptee -> specificRequest();
    }
private:
    Adaptee* m_adaptee;

};

/*
 * @brief: 类适配
 */
class Adapter1 : public Target,private Adaptee
{
public:
    Adapter1(){}
    ~Adapter1() {}
    virtual void request()
    {
        this -> specificRequest();
    }
};



#endif //TARGET_H
