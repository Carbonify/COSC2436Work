#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <cassert>

using namespace std;

struct binaryTreeNode
{
  int info;
  binaryTreeNode *left;
  binaryTreeNode *right;
};

class binaryTree {
private:
  binaryTreeNode *root;
  int height(binaryTreeNode* p) const;
  int max(int x, int y) const;
  void destroy(binaryTreeNode* &p);

public:
  binaryTree();
  int treeHeight() const;
  void insert(const int& insertItem);
  ~binaryTree();

  bool isEmpty() const;
  bool isFull();
};

void BSTTraverse(binaryTreeNode* node, bool& foundProblem) {
  if (!node)
    return;

  //only one child
  if( (!node->left && node->right) || (node->left && !node->right)) {
    foundProblem = true;
  }

  BSTTraverse(node->left, foundProblem);
  BSTTraverse(node->right, foundProblem);
}


bool binaryTree::isFull()
{
  bool foundProblem = false;
  BSTTraverse(root, foundProblem);
  return !foundProblem;
}


// DO NOT MODIFY CODE BELOW THIS LINE
// -----------------------------------
binaryTree::binaryTree()
{
  root = NULL;
}

bool binaryTree::isEmpty() const
{
  return(root == NULL);
}

int binaryTree::height(binaryTreeNode *p) const
{
  if (p == NULL)
    return 0;
  else
    return 1 + max(height(p->left), height(p->right));
}
int binaryTree::max(int x, int y) const
{
  if (x >= y)
    return x;
  else
    return y;
}

int binaryTree::treeHeight() const
{
  return height(root);
}


void binaryTree::insert(const int& insertItem)
{
  binaryTreeNode *current; //pointer to traverse the tree
  binaryTreeNode *trailCurrent; //pointer behind current
  binaryTreeNode *newNode; //pointer to create the node

  newNode = new binaryTreeNode;
  assert(newNode != NULL);
  newNode->info = insertItem;
  newNode->left = NULL;
  newNode->right = NULL;

  if (root == NULL)
    root = newNode;
  else
    {
      current = root;
      while (current != NULL)
        {
          trailCurrent = current;
          if (current->info == insertItem)
            {
              cerr << "The insert item is already in the list-";
              cerr << "duplicates are not allowed." << insertItem << endl;
              return;
            }
          else if (current->info > insertItem)
            current = current->left;
          else
            current = current->right;
        }
      if (trailCurrent->info > insertItem)
        trailCurrent->left = newNode;
      else
        trailCurrent->right = newNode;
    }
}

void binaryTree::destroy(binaryTreeNode* &p)
{
  if (p != NULL)
    {
      destroy(p->left);
      destroy(p->right);
      delete p;
      p = NULL;
    }
}

binaryTree::~binaryTree()
{
  destroy(root);
}

#endif
