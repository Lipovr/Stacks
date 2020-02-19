#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

class Stack
{
public:
    Stack() {
        std::cout << "Stack::ctor\n";
    }
    virtual ~Stack(){
        std::cout << "Stack::dtor\n";
    };
    virtual void push_back(int d)=0;
    virtual int pop_back()=0;
    virtual void print()=0;
};

#endif // STACK_H_INCLUDED
