#include "target.h"
int main(int argc , char* argv[])
{
    Target* tar = new Adapter(new Adaptee());
    tar->request();
    delete tar;

    Target* tar1 = new Adapter1();
    tar1->request();
    delete tar1;

    return 0;


}
