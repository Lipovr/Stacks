#ifndef SUBFORWARDLIST_H_INCLUDED
#define SUBFORWARDLIST_H_INCLUDED
#include "Stack.h"
struct subfl
{
    int data;
    subfl *next;
};

class Subforwardlist: public Stack
{
public:
    Subforwardlist();                       //+
    ~Subforwardlist();                      //+
    void push_back(int d);                  //+
    int pop_back();                         //+
    void push_forward(int d);               //+
    int pop_forward();                      //+
    unsigned int get_size();                //+
    void clear();                           //+
    void push_where(int d, unsigned int n); //+
    void erase_where(unsigned int n);       //+
    void print();
    int get_last_data();
private:
    subfl* head;
    subfl* last;
    unsigned int size;
};


#endif // SUBFORWARDLIST_H_INCLUDED
