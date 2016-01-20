#include "graph.h"

using namespace std;

void linklist::push( newtp d, int pos) // Adding elemant method
{

    node* newnode = new node; // Creating new element
    newnode->data = d; // filling element with new data
    if(first == NULL)   // If it first element in the list
    {
        newnode->next = newnode;
        newnode->pred = newnode;
        first = newnode; // first  point to it
    }
    else
    {
        node* temp = first; // Creating current pointer
        for ( int i = pos; i > 1; i--,temp=temp->next); // Cycle
            temp->pred->next = newnode;
            newnode->pred = temp->pred;
            newnode->next = temp; // Adding before current pointer
            temp->pred = newnode;
    }
}

newtp linklist::pop( int pos) // Deleting element method by index
{
  if(first == NULL)  return 0; // If list is NULL
  newtp val;
  if(first == first ->next) // If it is last element in the list
  {
      val = first->data;
      delete first;
      first = NULL;
  }
  else
 {
      node* temp = first;
      for ( int i = pos; i > 1; i--, temp = temp->next);
          if( temp == first) first = temp->next;
              temp->pred->next = temp->next; // Deleting temporary element
              temp->next->pred = temp->pred;
              val = temp->data;
              delete temp;
  }
  return val;
}

void linklist::clean() // Clear list
{
    if(first == NULL) return ;
    for ( node* newnode = first->next; newnode!=first; newnode = newnode->next) delete newnode;
    delete first;
    first = NULL;
}

void linklist::view() // View elements in the list
{
    if(first == NULL) return ;
    node* newnode = first;
    do
    {
        cout << newnode->data << endl;
        newnode = newnode->next;
    } while(newnode!=first);
}

void graph::addVertex(char *inlusion)
{

}

void graph::addVertex(vertex *parent, char *inclusion)
{

}

vertex graph::getVertex(char *inclusionname)
{
  vertex tempel;

  return tempel;
}

void graph::delVertex(vertex *newnode)
{

}

void graph::viewTree()
{

}
