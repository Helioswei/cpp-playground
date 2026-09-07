#ifndef KNOWDEFAULTFUN_H
#define KNOWDEFAULTFUN_H
/*
 *Know what functions C++ silently writes and calls
 *条款05：了解c++类默认编写并调用哪些函数
 * 1，copy构造函数
 * 2，copy assignment操作符
 * 3，default 析构函数
 * 4，default 构造函数
 * 所有这些函数都是 public 且 inline
 *
 */

class Empty {};

class Empty()
{
public:
    Empty();//default 构造函数
    Empty(const Empty&);//copy 构造函数
    ~Empty();//析构函数，，是否是virtual见稍后说明
    Empty& operator=(const Empty&);//copy assignment操作符
};
/*
 *如果自己声明了一个构造函数，编译器于是不再为它创建default构造函数。
 * */














#endif //KNOWDEFAULTFUN_H
