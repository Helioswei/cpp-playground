#ifndef MAKEINTERFACEEASY_H
#define MAKEINTERFACEEASY_H
/*
 *Make interfaces easy to use correctly and hard to use incorrectly
 *条款18：让接口容易被正确使用，不易被误用。
 *
 * Treat class design as type design
 * 条款19：设计class犹如设计type
 * 1，新type的对象应该如何被创建和销毁？这会影响到你的class的构造函数和析构函数以及内存分配函数
 *      和释放函数的设计；
 * 2，对象的初始化和对象的赋值该有什么样的差别？这个答案决定你的构造函数和赋值操作符的行为以及期间
 *      的差异。很重要的是被混淆了“初始化”和赋值，因为它们对应于不同的函数调用。
 * 3，新type的对象如果被passed by value ，意味着什么？记住，copy构造函数用来定义一个type的pass-by-value该
 *      如何实现。
 * 4，什么是新type的“合法值”？对class的成员变量而言，通常只有某些数值集是有效的。那些数值集决定了你的class
 *      必须维护的约束条件，也就决定了你的成员函数必须进行的错误检查工作。
 *
 * Prefer pass-by-reference-to-const to pass-by-value
 * 条款20：宁以pass-by-reference-to-const 替换 pass-by-value-
 * 1，尽量以pass-by-referece-to-const 替换pass-by-value.前者通常比较高效，并可避免切割问题
 * 2，以上规则并不适用于内置类型以及STL的迭代器和函数对象。对它们而言，pass-by-value往往比较适当。
 *
 *
 * Don't try to return a reference when you must return an object
 * 条款21：必须返回对象时，别妄想返回其reference
 * 1，绝不要返回pointer或referenc指向一个local stack对象，或返回reference指向一个heap-allocated对象，或
 *      返回pointer或reference 指向一个local static对象而有可能同时需要多个这样的对象。
 *
 *
 * Declare data members private
 * 条款22：将成员变量声明为private
 * 1，切记将成员变量声明为private。这可赋予客户访问数据的一致性，可细微划分访问控制，允许约束条件获取保证，并
 *      提供class作者以充分的实现弹性。
 * 2，protected并不比public更具封装性。
 *
 * Prefer non-member non-friend functions to  member functions
 * 条款23：宁以non-member non-friend 替换member函数
 * 1, 宁可拿non-member non-friend函数替换member函数。这样做的可以增加封装性，包裹弹性和机能扩充性
 */
class WebBrowser
{
public:
    void clearCache();
    void clearHistory();
    void removeCookies();
    void clearEverything()
    {
        clearCache();
        clearHistory();
        removeCookies();
    }
};

void clearBrowser(WebBrowser& wb)
{
    wb.clearHistory();
    wb.clearCache();
    wb.removeCookies();
}

/*
 *那么，哪一个比较好呢？是member函数clearEverything()还是non-member函数clearBrowser()?
 * non-member 函数更好
 */


#endif //MAKEINTERFACEEASY_H
