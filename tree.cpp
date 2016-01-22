#include "tree.h"

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
  
}

void arbitarytree::addLeaf(leaf *newleaf)
{

}

void arbitarytree::addLeaf(leaf *parentleaf, leaf *newleaf)
{

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
