#include "command.h"
int main(int argc , char* argv[])
{
    Reciever* rec = new Reciever;
    Command *com = new ConcreteCommand(rec);
    Invoker *invoker = new Invoker(com);
    invoker->call();



    return 0;


}
