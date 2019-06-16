#include "adjancencylist.h"


AdjacencyList::AdjacencyList()
{

}



void AdjacencyList::insertFor(City src, City dest) //associates each vertex in the graph with a collection of its neighboring edges
{

    bool found = false;
    for(int i=0; i<flights.getLength(); i++)
    {
        if(flights[i].getData() == src)
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        AdjNode<City> temp(src);
        flights.append(temp);
        flights[flights.getLength()-1].edges.append(dest);
    }
    else
    {
        int holder = 0;
        for(int i=0; i<flights.getLength(); i++)
        {
            if(flights[i].getData() == src)
            {
                holder = i;
            }
        }

        flights[holder].edges.append(dest);
    }

    src.setCost(dest.getCost());
    src.setTime(dest.getTime());
    dest.setTime(0);
    dest.setCost(0);

    found = false;

    for(int i=0; i<flights.getLength(); i++)
    {
        if(flights[i].getData() == dest)
        {
            found = true;
            break;
        }
    }

    if(!found)
    {
        AdjNode<City> temp(dest);
        flights.append(temp);
        flights[flights.getLength()-1].edges.append(src);
    }
    else
    {
        int holder = 0;
        for(int i=0; i<flights.getLength(); i++)
        {
            if(flights[i].getData() == dest)
            {
                holder = i;
            }
        }

        flights[holder].edges.append(src);
    }

}





AdjNode<City>& AdjacencyList::operator[](int index)
{

    return flights[index];


}

DLList<City> &AdjacencyList::find(City cita)
{
    AdjNode<City> temp(cita);

 for(int v = 0; v < flights.getLength(); v++)
 {

   if(flights[v] == temp)
   {
       return flights[v].edges;
   }

 }
 throw exception();
}

void AdjacencyList::printList()
{

    for(int i = 0; i < flights.getLength(); i++)
    {
         flights[i].getData().display();
         cout << "->\t";

         for(int z = 0; z <flights[i].edges.getLength(); z++)
        {
             flights[i].edges[z].display();
             cout << " -> ";

         }
          cout << endl;

    }


}


