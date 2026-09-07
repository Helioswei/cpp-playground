#ifndef USECONST_H
#define USECONST_H
/*
 * Use const whenever possible
 *条款:尽可能使用const
 *      1,将某些东西声明为const可帮助编译器侦探出错误用法，const可被施加于任何作用域内的对象，函数
 *      参数，函数返回值，成员函数本体。
 *
 *
 */
#include "basic.h"
char greeting[] = "Hello";//non-const pointer, non-const data
char* p = greeting;//non-const pointer, non-const data
const char* p = greeting;//non-const pointer, const data
char* const p = greeting;//const pointer, non-const data
const char* const p = greeting;//const pointer, const data


#endif //USECONST_H
