#ifndef HAVEOPETATORTHIS_H
#define HAVEOPETATORTHIS_H
/*
 *
 * Have assignment operators return a reference to *this
 * 条款10：令operator=返回一个reference to *this
 */

class Widget()
{
public:
    /*
     * 这个协议适用于+=，-=，*=等等
     * */
    Widget& operator+=(const Widget & rhs)
    {
        return *this;
    }
    Widget& operator=(int rhs)
    {
        return *this;
    }

};



#endif //HAVEOPETATORTHIS_H
