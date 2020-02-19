#include <iostream>
#include "Subvector.h"

using namespace std;

void Subvector::resize(unsigned int newcapacity)
{
    if(newcapacity<0)
    {
        cout << "ERROR: Trying to resize with negative capacity\n";
    }
    if(newcapacity==0)
    {
        delete[] data;
        data=0;
        top=0;
        capacity=0;
    }
    else
    {
        if (newcapacity < top)
            cout << "WARNING: Resizing with capacity lower than current number of elements,\n elements at the end will be lost\n";
        int* newdata=new int[newcapacity];
        unsigned int i;
        for(i=0;i<top&&i<newcapacity;i++)
        {
            newdata[i]=data[i];
        }
        delete[] data;
        data=newdata;
        capacity=newcapacity;
        top=i;
    }
}

Subvector::Subvector(): top(0), capacity(1), data(new int[1])
{
    cout << "Subvector::ctor\n";
}
/*
Subvector::Subvector(unsigned int s): top(0), capacity(s), data(new int[s])
{
    //cout << "constructor\n";

}

//Subvector::Subvector(unsigned int s, int d): top(s), capacity(s), data(new int[s])
{
    for (unsigned int i=0; i<s; i++)
    {
        data[i]=d;
    }
    cout << "constructor\n";
}
*/
Subvector::~Subvector()
{
    if (data)
    {
        delete[] data;
    }
    cout << "Subvector::dtor\n";

}

void Subvector::push_back(int d)
{
    if (top==capacity)
    {
        resize(capacity*2);
    }
    data[top]=d;
    top++;
}

int Subvector::pop_back()
{
    if(top>0)
    {
        //cout << "top: " << top << "\n";
        top--;
        int d=data[top];
        /*if (top<=capacity/2)
            shrink_to_fit();
            */
        //cout << "top: " << top << "\n";

        return d;
    }
    cout << "ERROR: No elements to pop";

    return 0;
}

void Subvector::shrink_to_fit()
{
    //cout << capacity;
    resize(top);
    //cout << "\nSHRINK______SHRINK\n"<< capacity << "\n";
}

void Subvector::clear()
{
    top=0;
}

unsigned int Subvector::get_capacity()
{
    return capacity;
}

unsigned int Subvector::get_top()
{
    return top;
}

void Subvector::print()
{
    if (top)
    {
        for (unsigned int i=0; i<top; i++)
        cout << "element " << i << " is " << data[i] << "\n";
    }
    else cout << "No elements :(\n";
}
