#ifndef PERFERDEFINE_H
#define PERFERDEFINE_H
/*
 * Prefer consts, enums,and inlines to #define
 *条款02：尽量以const,enum,inline替换#define
 *      1,对于单纯常量，最好以const对象或者enum替换#define
 *      2，对于形似函数的宏，最好改用inline函数替换#define
 * */

#include "basic.h"
const double AspectRatio = 1.654;
const std::string authorName("Helio wei");


class GamePlayer
{
private:
    /*
     *这个仅仅是声明，旧版编译器不支持,它们不允许static成员在其声明式中获取初值，需要定义式
     */
    //static const int NumTurns = 5;
    enum { NumTurns = 5};
    int scores[NumTurns];
public:
    GamePlayer();
    void setScores();
    void getScores();
};

/*
 *旧版编译器显示的定义,请把这个式子放进一个实现文件而非头文件。由于
 *class 常量已在声明时获取初值，因此定义时不可以在设置初值
 * */
//const int GamePlayer::NumTurns;
GamePlayer::GamePlayer()
{
    setScores();
}

void GamePlayer::setScores()
{
    for (int i = 0; i < NumTurns; i++)
    {
        scores[i] = i * 10;
    }
}
void GamePlayer::getScores()
{
    for (int i = 0; i < NumTurns; i++)
    {
        PR<int>(scores[i]);
    }
}



#endif //PERFERDEFINE_H
