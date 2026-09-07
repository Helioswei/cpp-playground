#include "originator.h"
//备忘录状态
int main(int argc , char* argv[])
{
    Originator *o = new Originator();
    o->setState("old");//备忘前状态
    o->printState();

    Memento* mt = o->createMemento();//将当前状态保存在备忘录中
    o->setState("new");//修改状态
    o->printState();
    o->restoreToMemento(mt);//恢复修改前的状态
    o->printState();

    return 0;


}
