#ifndef FLYWEIGHTFACTORY_H
#define FLYWEIGHTFACTORY_H
#include "./flyweight.h"
#include <map>
class FlyWeightFactory
{
public:
    FlyWeightFactory() {}
    ~FlyWeightFactory()
    {
        m_map.clear();

    }
    FlyWeight* getFlyweight(std::string state)
    {
        if (m_map.find(state) != m_map.end())
        {
            return m_map[state];
        }
        else
        {
            FlyWeight* flyWeight = new ConcreteFlyWeight(state);
            m_map.insert(std::pair<std::string, FlyWeight*>(state, flyWeight));

            return flyWeight;
        }

    }

private:
    std::map<std::string, FlyWeight*> m_map;
};














#endif //FLYWEIGHTFACTORY_H
