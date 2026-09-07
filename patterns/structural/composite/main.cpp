#include "./composite.h"

int main(int argc, char* argv[])
{

    Leaf* leaf = new Leaf;
    leaf->operation();

    Composite* com  = new Composite;
    com ->add(leaf);
    com->operation();

    Component* con = com ->getChild(0);
    con->operation();

    delete leaf;
    delete com;


    return 0;
}
