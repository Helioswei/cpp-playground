#ifndef STORENEWOBJECT_H
#define STORENEWOBJECT_H

/*
 * Store newed objects in smart pointers in standalone statements
 * 条款17：以独立语句将newed对象置于智能指针中
 * 以独立语句将newed对象存储于智能指针内。如果不这样做，一旦异常被抛出，有可能导致
 * 难以察觉的资源泄漏
 *
 * */

int priority();
void processWidget(std::shared_ptr<Widget> pw, int priority);

processWidget(std::shared_ptr<Widget>(new Widget), priority());

//调用priority();
//执行new Widget;
//调用std::shared_ptr 构造函数
//c++编译器执行这的次序是不一定的，new Widget会在std::shared_ptr之前，其他的不确定


#endif //STORENEWOBJECT_H
