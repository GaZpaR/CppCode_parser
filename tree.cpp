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
  nqnt++;
  parent->child.push_back(*newleaf);
  leaf* tleaf = parent->child.data();
  tleaf->parent = parent;
  tleaf->cntnumber = nqnt;

  links.push_back(tleaf);
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

leaf* retleaf;

// Searching of parent leaf
leaf* arbitarytree::searchLeaf(char *leafname)
{
  leaf **pleaf;

  pleaf = links.data();

  if(checkmatch(leafname, *pleaf)) return *pleaf;
  for(size_t i=0; i < links.size(); i++){
    pleaf++;
    if(checkmatch(leafname, *pleaf)) return *pleaf;
  }

  return retleaf;
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
  delete[] choiceleaf->name;
  delete[] choiceleaf->content;
  delete[] choiceleaf;
}

void arbitarytree::delTree(void)
{
  leaf **someleaf = links.data();

  for(size_t i=0; i < links.size(); i++){
    delLeaf(*someleaf);
    someleaf++;
  }
  links.clear();
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
