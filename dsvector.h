#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>
#include <iterator>
#include <cstring>



using namespace std;
template <typename P>


class DSVector
{

private:
    P* data;
    int capacity;
    int size;
public:
    typedef P* iterator;
    DSVector();
    DSVector(const DSVector&);
    ~DSVector();
    DSVector& operator=(const DSVector&);
    P& operator [](int);
    void pushback(const P& item);
    iterator begin();
    iterator end();
    void resize();
    void reserve(int);
    void display();
    int getSize() const;
    void swap(int, int);
    //friend ostream& operator<<(ostream&, const DSVector&);
};

template <typename P>
DSVector<P>::DSVector()
{
    size = 0;
    capacity = 0;
    data = new P[capacity];




}

template <typename P>
DSVector<P>::DSVector(const DSVector<P>& pot)
{

    size = pot.size;
    capacity = pot.capacity;
    data = new P[pot.size];
    for(int i = 0; i < size; i++)
    {

    data[i] = pot.data[i];
    }



}
template <typename P>
DSVector<P>::~DSVector()
{
    delete[] data;
}

template <typename P>
DSVector<P>& DSVector<P>::operator=(const DSVector& DS)
{
      this->size = DS.size;
      this->capacity = DS.capacity;
      this->data = DS.data;
      return *this;
}


template <typename P>
void DSVector<P>::pushback(const P& item)
{

    if(size>=capacity)
    {
     resize();
     }

    data[size] = item;

    size++;


}


//allocates double the amount of data as previous
template <typename P>
void DSVector<P>:: resize()
{
     /*

        if (count < size)
           size = count;
       else if (count > capacity) {
           P* temp = new P[count];
           for (int i = 0; i < size; i++)
               temp[i] = data[i];
           delete[] data;
           data = temp;
          }

    P* temp = new P[moreCapacity];
    for(int i = 0; i < size; i++)
    {
        temp[i] = data[i];


    }
    delete[] data;
    data = temp;
    temp = nullptr;
    capacity = moreCapacity;

   */
              capacity = capacity ? capacity*2 : 1;
              P* temp = new P[capacity];
              for(int i = 0; i < size; i++)
              {
                  temp[i] = data[i];


              }
              delete[] data;
              data = temp;
              temp = nullptr;










}
/*
template <typename P>
void DSVector<P>:: reserve(int new_cap)
{
    if(new_cap>capacity)
    {

        capacity= new_cap;

    }
}
*/

template<class P>
P& DSVector<P>::operator [](int k)
{

    return data[k];

}


template <typename P>
void DSVector<P>::display()
{
    for(int i = 0; i< size; i++)
    cout<< data[i] << endl;
}


template<typename P>
int DSVector<P>::getSize() const {
    return size;
}

template<class P>
typename DSVector<P>::iterator DSVector<P>::begin()
{
    return data;
}

template<class P>
typename DSVector<P>::iterator DSVector<P>::end()
{
    return data + getSize();
}

template<typename P>
void DSVector<P>::swap(int t1, int t2) {
    int tmp(t1);
    t1=t2;
    t2=tmp;
}
/*
ostream& operator<<(ostream& os, const DSVector& s)
{
    if (s.size > 0)
    {
        for (int z=0; z < s.size; z++)
            os << s[z];
    }
    else
       os << "";

    return os;

}
*/

#endif // DSVECTOR_H

