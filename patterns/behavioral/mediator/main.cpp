#include "colleague.h"
#include "mediator.h"
int main(int argc , char* argv[])
{
    ColleageA* pa = new ColleageA;
    ColleageB* pb = new ColleageB;
    ConcreteMediator* mediator = new ConcreteMediator(pa, pb);
    pa->setState("ColleageA state");
    pb->setState("ColleageB state");
    pa ->action();
    pb ->action();



    delete pa, pb, mediator;

    return 0;


}
