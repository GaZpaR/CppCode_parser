#include <iostream>
#include <string.h>
#include <vector>

struct leaf{
   char *name;
   uint8_t *content;
   uint32_t child_count;
   std::vector< leaf* > child;
};

class arbitarytree{
  private:
    leaf root;
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

    // Create arbitary leaf
    virtual leaf* createLeaf(char *leafname, uint8_t *file, size_t size);

    // Append arbitary leaf to the parent
    virtual void appendLeaf(leaf *parent, leaf *newleaf);

    // Adding new leaf to the root
    virtual void addLeaf(leaf *newleaf);
    // Adding new leaf to the parent leaf
    virtual void addLeaf(leaf *parentleaf, leaf *newleaf);

    // Deleting leaf and it's children
    virtual void delLeaf(leaf *choiceleaf);

    // Deleting root and all subtrees
    virtual void delTree(void);

    // Geting leaf by it's name
    virtual leaf* getLeaf(char *filename);

    // Show subtree
    virtual void viewSubTree(leaf *choiceleaf);

    // Show tree
    virtual void viewTree(void);

};
