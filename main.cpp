#include <iostream>


using namespace std;
#include "Subforwardlist.h"
#include "Subvector.h"


int main()
{
    Stack* stack_array[4];
    for (int i=0; i<4;i++)
    {
        if (i%2==0)
        {
            stack_array[i] = new Subforwardlist;
        }
        else stack_array[i] = new Subvector;
        for (int j=0; j<5; j++)
        {
            stack_array[i]->push_back(j);
        }
    }
    for (int i=0; i<4;i++)
    {
        stack_array[i]->print();
    }
    for (int i=0; i<4;i++)
    {
        cout << stack_array[i]->pop_back()  << "\n";
    }
    delete[] stack_array;
    return 0;
}
