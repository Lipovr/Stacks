#include <iostream>


using namespace std;
#include "Subforwardlist.h"
#include "Subvector.h"


int main()
{
    cout << "***Stacks***\n\n";
    cout << "Creating array of four stacks and fillig them with elements\n";
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
    cout << "Printing contents of each:\n";
    for (int i=0; i<4;i++)
    {
        stack_array[i]->print();
    }
    cout << "Poping back from each and displaying results:";
    for (int i=0; i<4; i++)
    {
        cout << stack_array[i]->pop_back()  << "\n";
    }
    for (int i=0; i<4; i++) {
        delete stack_array[i];
        stack_array[i]=0;
    }
    return 0;
}
