#ifndef NONMEMBER_H
#define NONMEMBER_H
/*
 *
 * Declare non-member functions when type conversions should apply to all parameters
 * 条款24：若所有参数皆需要类型转换，请为此采用non-member函数
 * 1, 如果你需要为某个函数的所有参数（包括被this指针所指的那个隐喻参数）进行类型转换，那么
 *      这个函数必须是个non-member.
 *
 *
 * Consider support for a non-throwing swap
 * 条款25：考虑写出一个不抛出异常的swap的函数
 *
 *
 */

class Widget
{
    public:
        Widget(const Widget& rhs);
        Widget& operator=(const Widget& rhs)
        {
            *pIml = *(rhs.pIml);
        }
        void swap(Widget& other)
        {
            using std::swap;//这个声明是必要的
            swap(pIml, other.pIml);//若要置换Widget 就置换其pIml指针。
        }
    private:
        WidgetImpl* pImpl;//WidgetImpl 存放Widget的成员变量
};
//特例化std::swap
namespace std{
    template<> swap<Widget>(Widget& a, Widget& b)
    {
        a.swap(b);
    }

}




#endif //NONMEMBER_H
