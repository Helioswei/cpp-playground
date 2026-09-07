#include "abstractionImp.h"
#include "abstraction.h"
int main(int argc , char* argv[])
{
    AbstractionImp* imp1 = new AbstractionImp1();
    AbstractionImp* imp2 = new AbstractionImp2();
    Abstraction* abstract = static_cast<Abstraction*>(new RefinedAbstraction(imp2));

    abstract->operation();

    return 0;


}
