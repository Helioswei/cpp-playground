#ifndef INITIALIZE_H
#define INITIALIZE_H
/*
 *Make sure that objects are initialized before they are used
 *条款：确定对象被使用前已被初始化
 *  1,对于无任何成员的内置类型，你必须手动的完成此事；
 *  2，至于内置以外其他东西，初始化责任落在构造函数身上。规则很简单：
 *      确保每一个构造函数都将对象的每个成员初始化;
 *  3,为免除”跨编译单元之初始化次序问题“,请以local static 对象替换non-local static 对象
 *
 *
 */

#include "basic.h"
class Test
{
public:
    Test(): m_name(), m_address(), m_number(0) {}
    void printValue()
    {
        PR<std::string>(m_name);
        PR<std::string>(m_address);
        PR<int>(m_number);
    }
private:
    std::string m_name;
    std::string m_address;
    int m_number;
};

Test& getTest()
{
    static Test test;
    return test;
}


#endif //INITIALIZE_H
