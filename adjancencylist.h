#ifndef ADJANCENCYLIST_H
#define ADJANCENCYLIST_H
#include <iostream>
#include "dllist.h"
#include "city.h"

using namespace std;


template <typename P>

class AdjNode
{

private:
    P data;


public:
    DLList<P> edges;
    AdjNode();
    AdjNode(P val);
    bool operator==(const AdjNode<P>&);
    P& getData();


};

template <typename P>
AdjNode<P>::AdjNode()
{

}

template <typename P>
AdjNode<P>::AdjNode(P val)
{

    data = val;

}

template <typename P>
P& AdjNode<P>::getData()
{

    return data;

}



template <typename P>
bool AdjNode<P>::operator==(const AdjNode<P>& Aj)
{
    if(data == Aj.data)
        return true;
     else
        return false;


}


class AdjacencyList
{

private:


public:
    DLList<AdjNode<City>> flights;
    AdjacencyList();
    void insertFor(City, City);
    DLList<City>& find(City);
    void printList();
    //overloaded brackets operator
    AdjNode<City>& operator[](int);
};

#endif // ADJANCENCYLIST_H
