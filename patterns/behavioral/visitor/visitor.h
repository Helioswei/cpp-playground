#ifndef VISITOR_H
#define VISITOR_H

class Visitor
{
    public:
        Visitor(){}
        virtual ~Visitor(){}
        virtual void visitElementA(Element* elm) = 0;
        virtual void visitElementB(Element* elm) = 0;
};

class ConcreteVisitorA : public Visitor
{
    public:
        ConcreteVisitorA(){}
        virtual ~ConcreteVisitorA(){}
        virtual void visitElementA(Element* elm){
        
        }
        virtual void visitElementB(Element* elm)
        {}
};


class ConcreteVisitorB : public Visitor
{
    public:
        ConcreteVisitorB(){}
        virtual ~ConcreteVisitorB(){}
        virtual void visitElementA(Element* elm){
        
        }
        virtual void visitElementB(Element* elm)
        {}
};


#endif //VISITOR_H
