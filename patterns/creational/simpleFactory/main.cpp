#include "product.h"
int main(int argc , char* argv[])
{

    std::string type;

    if (argc == 2)
    {
        type = std::string(argv[1]);
        Product* pro = Factory::getProduct(type);
        pro->use();
        delete pro;
    }
    else
    {
        std::cout << "Please choose product" << std::endl;
    }

    return 0;


}
