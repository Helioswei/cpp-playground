#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>

//命令模式
//抽象命令类
class Command
{
    public:
        Command(){}
        virtual ~Command(){}
        virtual void execute(){}
};
//命令的接收者
class Reciever
{
    public:
        Reciever(){}
        ~Reciever(){}
        void action(){
            std::cout << "Reciever Action" << std::endl;
        
        }

};

//具体命令类
class ConcreteCommand : public Command
{
    public:
        ConcreteCommand(Reciever* rec):m_rec(rec){}
        ~ConcreteCommand(){}
        virtual void execute()
        {
            m_rec->action();
        
        }
    private:
        Reciever* m_rec;

};


//命令的调用者    
class Invoker
{
    public:
        Invoker(Command *command):m_com(command){}
        ~Invoker(){
        
        }
        void call()
        {
            std::cout << "Invoker call" << std::endl;
            m_com->execute();
        }
    private:
            Command *m_com;
};








#endif //COMMAND_H
