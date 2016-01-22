#include "tree.h"
#include <stdbool.h>
using namespace std;

leaf* arbitarytree::createLeaf(char *leafname, uint8_t *file, size_t size)
{
  leaf* newleaf = new leaf;
  newleaf->name = new char[strlen(leafname)+1];
  memcpy(newleaf->name, leafname, strlen(leafname));

  newleaf->content = new uint8_t[size+1];
  memcpy(newleaf->content, file, size);

  return newleaf;
}

void arbitarytree::appendLeaf(leaf *parent, leaf *newleaf)
{
  parent->child.push_back(*newleaf);
  leaf* tleaf = parent->child.data();
  tleaf->parent = parent;
}

void arbitarytree::addLeaf(char *leafname, uint8_t *file, size_t size)
{
  appendLeaf(&root, createLeaf(leafname, file, size));
}


bool checkmatch(char *leafname, leaf *someleaf)
{
  if(strcmp(someleaf->name, leafname) == 0) return true;
  else return false;
}

leaf*  retleaf;
vector<leaf*> leafstack;
// Recursive searching of parent leaf
leaf* arbitarytree::searchFromRoot(char *leafname, leaf *someleaf)
{
  leaf *pleaf;

  if(checkmatch(leafname, someleaf)) return someleaf;
  cout << "Size of root childs is: " << someleaf->child.size() << endl;
  if(someleaf->child.size() > 0) pleaf = someleaf->child.data();
  else return retleaf;

  for(size_t i=0; i < someleaf->child.size(); i++){
    if(checkmatch(leafname, someleaf)) return pleaf;
    pleaf++;
  }
  cout << "Here is breaking prog" << endl;
  return searchFromRoot(leafname, pleaf--);
}

leaf* arbitarytree::searchLeaf(char *leafname)
{
  // Starting search from root
  return searchFromRoot(leafname, &root);
}

void arbitarytree::addLeaf(char *parentleaf, char *leafname, uint8_t *file, size_t size)
{
  leaf *parent = searchLeaf(parentleaf);

  if(parent == retleaf) cout << "There is no such parent leaf" << endl;
  else{
    cout << "Parent leaf name is " << parent->name << endl;
    appendLeaf(parent, createLeaf(leafname, file, size));
  }

}

void arbitarytree::delLeaf(leaf *choiceleaf)
{

}

void arbitarytree::delTree(void)
{

}

leaf* arbitarytree::getLeaf(char *filename)
{
  leaf *pleaf;
  return pleaf;
}

void arbitarytree::viewSubTree(leaf *choiceleaf)
{

}

void arbitarytree::viewTree(void)
{

}
