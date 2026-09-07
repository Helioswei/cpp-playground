#ifndef USEOBJECTMA_H
#define USEOBJECTMA_H
/*
 *Use objects to manage resources
 *条款13：以对象管理资源

 *Think carefully about copying behavior in resource-managing casses
 *条款14：在资源管理类中小心copying行为

 *Provide accesss to raw resources in resource-managing classes.
 *条款15：在资源管理类中提供对原始资源的访问
 *1，资源在构造期间获得，在析构期间释放。
 *c++11后可以使用智能指针来管理申请的资源

 *Use the same form in corresponding uses of new and delete
 *条款16：成对使用new和delete时要采取相同形式
 *1,如果你在new表达式中使用[],必须在相应的delete表达式中也使用[].如果你在new表达式中不使用[],一定
 *不要在相应的delet表达式中使用[]
 */


#endif //USEOBJECTMA_H
