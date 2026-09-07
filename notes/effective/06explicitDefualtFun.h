#ifndef EXPLICITDEFAULT_H
#define EXPLICITDEFAULT_H
/*
 *Explicitly disallow the use of compiler-generated functions you do not want
 *条款06：若不想使用编译器自动生成的函数，就该明确的拒绝
 *
 */


/*
 *阻止声明编译器自动生成的函数的关键是，所有编译器产生的函数都是public。为阻止这些函数
 *被创建出来，我们可以自行声明它们，但这里并没有什么需求使你必须将它们声明为public。
 *因此你可以将copy构造函数或copy assignment操作符声明为private。
 *一般而言，这种做法并不安全，因为member函数和friend函数还是可以调用你的private函数
 *我们可以声明为private，并且不写形参来避免这种情况
 *
 * c++11 可以使用delete函数
 * */

#endif //EXPLICITDEFAULT_H
