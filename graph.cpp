#include "graph.h"
#include "string.h"

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

//Adding vertex to the root
void graph::addVertex(char *inclusion)
{
    vertex* newnode = new vertex; // Creating new element
    char *tempdata = new char[(strlen(inclusion)+1)];
    memcpy(tempdata, inclusion, strlen(inclusion));
    newnode->data = tempdata; // filling element with new data
    root.qchild++;

    if(root.qchild == 1)   // If it first element in the list
    {
        newnode->parent = &root;
        newnode->next = newnode;
        newnode->prev = newnode;

    }
    else
    {
        vertex* temp = newnode; // Creating current pointer
        for ( int i = root.qchild; i > 1; i--,temp = temp->next); // Cycle
            temp->prev->next = newnode;
            newnode->prev = temp->prev;
            newnode->next = temp; // Adding before current pointer
            temp->prev = newnode;
    }
}

void graph::addVertex(vertex *parent, char *inclusion)
{
  vertex* newnode = new vertex; // Creating new element
  char *tempdata = new char[(strlen(inclusion)+1)];
  memcpy(tempdata, inclusion, strlen(inclusion));
  newnode->data = tempdata; // filling element with new data
  parent->qchild++;

  if(parent->qchild == 1)   // If it first element in the list
  {
      newnode->parent = parent;
      newnode->next = newnode;
      newnode->prev = newnode;

  }
  else
  {
      newnode->parent = parent;
      vertex* temp = newnode; // Creating current pointer
      for ( int i = parent->qchild; i > 1; i--,temp = temp->next); // Cycle
          temp->prev->next = newnode;
          newnode->prev = temp->prev;
          newnode->next = temp; // Adding before current pointer
          temp->prev = newnode;
  }
}

vertex graph::getVertex(char *inclusionname)
{
  vertex tempel;

  if(root.qchild == 1)  return root; // If list is NULL

  // If it is last element in the list
  if(&root == root.next){
        return root;
  } else{
      vertex* temp = root.next;

      if(strcmp(temp->data, inclusionname) == 0) return *temp;
      else{

      }

    }

  return tempel;
}

void graph::delVertex(vertex *node)
{

}

void graph::viewTree()
{

}
