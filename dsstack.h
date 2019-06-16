#ifndef DSSTACK_H
#define DSSTACK_H
#include "dllist.h"

using namespace std;

template <typename P>

class DSStack
{

private:


public:
    DLList<P> myStack;
     DSStack();
     void push(P);
     void pop();
     P& peak();
     bool isEmpty();
     bool contains(P);



};

template <typename P>
DSStack<P>::DSStack()
{




}



template <typename P>
void DSStack<P>::push(P entry)
{
    myStack.append(entry);


}

template <typename P>
void DSStack<P>::pop()
{

    myStack.pop();

}

template <typename P>
P& DSStack<P>::peak()
{

    int l = myStack.getLength();
    if(myStack.isEmpty() == false)
    {
      return myStack[l-1];
    }
    else {
        return myStack[0];
    }


}

template <typename P>
bool DSStack<P>::isEmpty()
{
    int l = myStack.length;

    if(l > 0)
        return false;
    else
        return true;

}

template <typename P>
bool DSStack<P>::contains(P key)
{

   return myStack.search(key);

}

#endif // DSSTACK_H
