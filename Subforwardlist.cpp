#include <iostream>
#include "Subforwardlist.h"
using namespace std;

Subforwardlist::Subforwardlist()
{
    cout << "Subforwardlist::ctor\n";

    head=last=0;
    size=0;
}


Subforwardlist::~Subforwardlist()
{

    cout << "Subforwardlist::dtor\n";

    clear();;
}


void Subforwardlist::clear()
{
    if(head)
    {
        subfl *temp;
        while (head->next)
        {
            temp=head->next;
            delete head;
            head=temp;
        }
        delete head;
        head=0;
        last=0;
        size=0;
        //cout << "ishead, clearing\n";
    }
    cout << "ERROR: list is empty, nothing to clear\n";
}


void Subforwardlist::push_back(int d)
{
    if(!last)
    {
        head=new subfl;
        last=head;
        head->next=0;
        head->data=d;
    }
    else
    {
        last->next=new subfl;
        last=last->next;
        last->next=0;
        last->data=d;
    }
    size++;
}


int Subforwardlist::pop_back()
{
    if (!head)
    {
        cout << "ERROR: No elements to pop\n";
        return 0;
    }
    int d=last->data;
    subfl* temp=head;

    if(last==head)
    {
        delete head;
        head=last=0;
        size=0;
        return d;
    }
    while (/*temp->next&&*/temp->next!=last)
    {
        temp=temp->next;
    }
    temp->next=0;
    delete last;
    last=temp;
    size--;
    return d;
    //cout << "-size\n";
}


unsigned int Subforwardlist::get_size()
{
    return size;
}


void Subforwardlist::push_forward(int d)
{
    subfl* newhead=new subfl;
    newhead->data=d;
    newhead->next=head;
    head=newhead;
    if (!last) last=head;
    size++;
}


int Subforwardlist::pop_forward()
{
    if(!head)
    {
        cout << "ERROR: No elements to pop\n";
        return 0;
    }
    int d=head->data;
    subfl*temp=head;
    head=head->next;
    if(!head)
    {
        last=0;
    }
    delete temp;
    size--;
    return d;
}


void Subforwardlist::push_where(int d, unsigned int n)
{
    if (n>=size-1)
    {
        //cout << "No place to push, pushing back\n";
        push_back(d);
        return;
    }
    subfl* temp=head;
    unsigned int i;
    for (i=0; i<n; i++)
    {
        temp=temp->next;
    }
    subfl* newelem= new subfl;
    newelem->data=d;
    newelem->next=temp->next;
    temp->next=newelem;
    size++;
}


void Subforwardlist::erase_where(unsigned int n)
{
    if (!head)
    {
        cout << "ERROR: list is empty, nothing to delete";
        return;
    }
    if (n>=size-1)
    {
        cout << "ERROR: trying to delete element from position that doesn't exist\n";
        return;
    }
    if(n==0)
    {
        pop_forward();
        return;
    }
    unsigned int i;
    subfl* temp=head;
    for(i=0; i<n-1; i++)
    {
        temp=temp->next;
    }
    subfl* to_del=temp->next;
    temp->next=temp->next->next;
    delete to_del;
    size--;
}

void Subforwardlist::print()
{
    if (!head)
    {
        cout << "No elements :( \nsize:" << size <<"\n";
        return;
    }
    subfl* temp=head;
    while(temp->next)
    {
        cout << temp->data <<" --> ";
        temp=temp->next;
    }
    cout << temp->data << "\n";
    cout << "size: " << size << "\n";
}


int Subforwardlist::get_last_data()
{
    if(last)
    return last->data;
    else
    {
        cout << "list is empty";
        return 0;
    }
}
