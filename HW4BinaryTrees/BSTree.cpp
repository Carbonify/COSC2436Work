#include "BSTree.h"
#include "BSTNode.h"
#include <string>


BSTree::BSTree()
{
  rootNode = nullptr;
}

BSTree::~BSTree()
{
  //implement destructor

}

int countHeight(BSTNode *start)
{
  int retd;
  if (nullptr == start)
  {
    return -1;
  }
  else
  {
    int ld = countHeight(start->getLeftChild());
    int rd = countHeight(start->getRightChild());

    return max(ld, rd) + 1;
  }

}


int BSTree::getHeight() const
{
  return countHeight(rootNode);
}


int countNodes(BSTNode* start)
{
  if (nullptr == start)
  {
    return 0;
  }
  else
  {
    return 1 + countNodes(start->getLeftChild()) + countNodes(start->getRightChild());
  }
}

int BSTree::getNumNodes() const
{
  return countNodes(rootNode);
}


string BSTree::getRepresentation()
{
  //implement function
}

BSTNode* BSTree::getNode(string key)
{
  //implement function
}


bool BSTree::addNode(string key)
{
  BSTNode* newNode = new BSTNode(key);
  addNode(newNode);
  return true;
}

bool addNodeHelper(BSTNode* toAdd, BSTNode* current) {
  if (toAdd->getKey().compare(current->getKey()) == 0) { //duplicate
    return false;
  } else if (toAdd->getKey().compare(current->getKey()) < 0) { //left hand
    if (!current->getLeftChild()) {
      current->setLeftChild(toAdd);
      return true;
    }
    return addNodeHelper(toAdd, current->getLeftChild());
  } else { //right hand
    if (!current->getRightChild()) {
      current->setRightChild(toAdd);
      return true;
    }
    return addNodeHelper(toAdd, current->getRightChild());
  }
}

bool BSTree::addNode(BSTNode* item)
{
  //implement function
  if (!rootNode) {
    rootNode = item;
    return true;
  }
  return addNodeHelper(item, rootNode);
}
