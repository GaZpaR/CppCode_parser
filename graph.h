#include <iostream>
#include <string.h>

typedef char* newtp;
struct node
{
    newtp data;    // Data
    uint32_t qchild;
    char *link;
    node* next;    // Pointer to the next element
    node* pred;    // Pointer to the previous element
};

class linklist // Link list class
{
private:
    node* first; // Pointer to the begin
public:
    linklist() { first = NULL; } // Init linklist
                                 // where is no usefull info

    void push( newtp d, int pos); // Adding elemant method
    newtp pop( int pos);  // Deleting element method
    void clean(); // Clean link list
    void view(); // Print list content to display
};

struct vertex
{
  char *data;       // Data
  uint32_t qchild;  // Children's quantity
  vertex* parent;     // Pointer to parent
  linklist children;
};


class graph{
  private:
    vertex root;
  public:
    graph(char *filename){
      //Filling rootname
      root.data = new char[strlen(filename + 2)];
      memcpy(root.data, filename, strlen(filename));

      //Initializing children's quantity
      root.qchild = 0;

      //Init root's paent address
      //root.parent = NULL;

      //root.children = NULL;
    };

    ~graph(){
      delete root.data;
    };

    //Adding to the root list of links
    virtual void addVertex(char *inlusion);

    //Adding to the arbitary vertex
    virtual void addVertex(vertex *parent, char *inclusion);

    //Get vertex
    virtual vertex getVertex(char *inclusionname);

    //Deleting arbitary vertex
    virtual void delVertex(vertex *newnode);

    virtual void viewTree();

};
