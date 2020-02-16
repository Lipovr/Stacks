#ifndef SUBVECTOR_H_INCLUDED
#define SUBVECTOR_H_INCLUDED
#include "Stack.h"
class Subvector: public Stack
{
    public:
    Subvector ();
    //Subvector (unsigned int s);
    //Subvector (unsigned int s, int d);
    ~Subvector();
    void push_back(int d);
    int pop_back();
    void resize(unsigned int newcapacity);
    void shrink_to_fit();
    void clear();
    unsigned int get_top();
    unsigned int get_capacity();
    void print();
    private:
    unsigned int top;
    unsigned int capacity;
    int* data;
};


#endif // SUBVECTOR_H_INCLUDED
