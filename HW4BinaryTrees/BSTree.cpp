#include "BSTree.h"
#include "BSTNode.h"


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

bool BSTree::addNode(BSTNode* item)
{
	//implement function
}


