#include <iostream>
#include <string.h>
#include <vector>

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
  vertex* firstchild;
  vertex* prev;
  vertex* next;
};

struct tree{
   char *name;
   uint8_t *content;
   uint32_t child_count;
   std::vector< tree* > child;
};

class arbitarytree{
  private:
    tree root;
  public:
    arbitarytree(char *rootfile, uint8_t *file, size_t size){
      root.name = new char(strlen(rootfile)+1);
      memcpy(root.name, rootfile, strlen(rootfile));

      root.content = new uint8_t[size+1];
      memcpy(root.content, file, size);

    }
    virtual ~arbitarytree(){

      delete root.content;
      delete root.name;
    }
    virtual void addLeaf();

    virtual void delLeaf();
    virtual void delSubTree();
    virtual void delTree();

    virtual tree getLeaf();

    virtual void viewSubTree();
    virtual void viewTree();

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
    };

    ~graph(){
      delete root.data;
    };

    //Adding to the root list of links
    virtual void addVertex(char *inclusion);

    //Adding to the arbitary vertex
    virtual void addVertex(vertex *parent, char *inclusion);

    //Get vertex
    virtual vertex getVertex(char *inclusionname);

    //Deleting arbitary vertex
    virtual void delVertex(vertex *node);

    virtual void viewTree();

};
