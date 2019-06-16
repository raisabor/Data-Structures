#ifndef DLLIST_H
#define DLLIST_H
#include <iostream>


using namespace std;

template <typename P>

class Node
{

private:


public:
    Node();
    P data;
    Node* next;
    Node* prev;




};

template <typename P>
Node<P>::Node()
{

    next = nullptr;
    prev = nullptr;
}


template <typename P>

class DLList
{
private:
    Node<P>* front;
    Node<P>* back;
    int length;
    Node<P>* Iter;

public:

    //overloaded operators, constructors and destructor
    DLList();
    DLList(const DLList&);
    DLList& operator=(const DLList&);
    P& operator[](const int);
    ~DLList();


    void prepend(const P&);
    void append(const P&);
    void pop();
    void shift();
    void display();
    bool search(P);

    //return type fucntions
    bool isEmpty();
    int getLength();

    //Iterator functions
    void resetIter();
    bool isIterValid();
    P& getIter();
    void stepIter();


};

template <typename P>
DLList<P>::DLList()
{
    front = nullptr;
    back = nullptr;
    Iter = nullptr;
    length = 0;

}

template <typename P>
DLList<P>::DLList(const DLList& original)
{
    Iter = front;
    //Is list empty?
      if (original.front == nullptr)
      {
        front = nullptr;
        back = nullptr;
        length = 0;
      }

      else
      {
        Node<P>* temp = original.front;

        length = 0;
        front = back = nullptr;

        while(temp != nullptr)
        {
          //create a new Node to enter into the new List
          Node<P>* node = new Node<P>;
          node->prev = nullptr;
          node->next = nullptr;
          node->data = temp->data;

          //add newNode to new List
          if(length == 0) //new list is empty
            front = back = node;
          else //add newNode to end of new List
          {
            back->next= node;
            node->prev = back;
            back = back->next;
          }

          ++length;
          temp = temp->next;
        }

      }

}


template <typename P>
DLList<P>& DLList<P>::operator=(const DLList& original)
{
    Iter = front;
    if(this != &original){
        length = original.length;
        if(original.length == 0)
            front = nullptr;
        else
        {
            length = original.length;
            this->~DLList();
            Node<P>* origPtr;
            Node<P>* lastPtr;
            origPtr = original.front;
            lastPtr = new Node<P>();
            lastPtr->data = origPtr->data;
            front = lastPtr;
            Node<P>* temp;


            while(origPtr != NULL) //cycle through the origin list
            {
                temp = new Node<P>();       //copy data in current node of origin list
                temp->data = origPtr->data;
                lastPtr->next = temp;  //add temp to end of this list
                lastPtr = lastPtr->next; //advance lastPtr to end of this list
                origPtr = origPtr->next; //go to next node in origList
            }
        }
    }
    return *this;
}

template <typename P>
P& DLList<P>::operator[](const int index) {
    Node<P>* right = this->front;

    for(int i = 0; i < index; i++)
    {
        right = right->next;
    }
    return right->data;
}


template <typename P>
DLList<P>::~DLList()
{

    Node<P>* current = front;
    if(current == nullptr)
        return;

    while(current != nullptr)
    {
            current = front->next;
            delete front;
            front = current;
    }
    back = nullptr;
}

template <typename P>
bool DLList<P>::isEmpty()
{
    if(length > 0)
        return false;
    else
        return false;



}

template <typename P>
bool DLList<P>::search(P key)
{

    Node<P>* temp = front;  // Initialize temp

       while (temp != nullptr)
       {
           if (temp->data == key)
               return true;
           temp = temp->next;
       }
       return false;



}

template <typename P>
void DLList<P>::append(const P& actual)
{
    Node<P>* temp = new Node<P>();
    temp->data = actual;
    if(front == nullptr)
    {
        front = back = temp;

    }
    else
    {
      back->next = temp;
      temp->prev= back;
      back = temp;


    }

    length++;


}

template <typename P>
void DLList<P>::pop()
{



    if(front == back)
        {

            delete back;
            front = back = nullptr;
        }
        else {
            Node<P>* temp = back;
            temp->prev = back->prev;
            temp->next = back->next;
            back = temp->prev;
            delete temp;
            back->next = nullptr;

        }



        length--;



}

template <typename P>
void DLList<P>::prepend(const P& actual)
{
    Node<P>* temp = new Node<P>();
    Iter = front;
    temp->data = actual;
    if(front == nullptr)
    {
        temp->next = nullptr;
        back = temp;
    }
    else
        temp->next = front;

    front = temp;
    length++;


}

template <typename P>
void DLList<P>::shift()
{

    Iter = front;
    if(front == back)
       {
           delete front;
           front = back = nullptr;
       }
       else
       {
           Node<P>* temp = front;
           front = temp->next;

           front->prev = nullptr;
           delete temp;
       }
         length--;


}

template <typename P>
int DLList<P>::getLength()
{
    return length;
}

template <typename P>
void DLList<P>::display()
{

    Node<P>* temp = new Node<P>;

    if(front != nullptr)
    {
        for(temp = front; temp != nullptr; temp=temp->next)
                      cout << temp->data << " ";
      cout << endl;
    }
    else
      cout << "The list is empty!" << endl;



}

// Iterator function implementations

template <typename P>
void DLList<P>::resetIter()
{
    Iter = front;
}

template <typename P>
bool DLList<P>::isIterValid()
{
    return Iter != nullptr;
}

template <typename P>
P& DLList<P>::getIter()
{
    return Iter->data;
}

template <typename P>
void DLList<P>::stepIter()
{
    //if(Iter->next != nullptr)
         Iter = Iter->next;
}


#endif // DLLIST_H




