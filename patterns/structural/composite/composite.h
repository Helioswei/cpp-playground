#ifndef COMPOSITE_H
#define COMPOSITE_H
#include <iostream>
#include <vector>
#include <algorithm>

//组合模式

class Component
{
public:
    Component() {}
    virtual ~Component() {}
    virtual void operation() {}
    virtual void add(Component& com) {}
    virtual void remove(Component& com) {}
    virtual Component* getChild(int index)
    {
        return nullptr;
    }
};

class Leaf : public Component
{
public:
    Leaf() {}
    ~Leaf() {}
    virtual void operation()
    {
        std::cout << "Leaf operation" << std::endl;
    }
};

class Composite : public Component
{
public:
    Composite() {}
    ~Composite() {}
    virtual void operation()
    {
        for (auto& comm : m_vec)
        {
            comm -> operation();
        }
    }
    virtual void add(Component* com)
    {
        m_vec.push_back(com);

    }
    virtual void remove(Component* com)
    {
        auto it = std::find(m_vec.begin(), m_vec.end(),com);
        if(it!= m_vec.end())
        {
        m_vec.erase(it);
        }

    }
    virtual Component* getChild(int index)
    {
        return m_vec[index];

    }
private:
    std::vector<Component*> m_vec;

};

#endif //COMPOSITE_H
