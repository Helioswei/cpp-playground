#ifndef CONTEXT_H
#define CONTEXT_H

class State;
class Context
{
public :
    Context();
    virtual void changeState(State* state);
    virtual void request();
private:
    State* m_state;
};









#endif //CONTEXT_H
