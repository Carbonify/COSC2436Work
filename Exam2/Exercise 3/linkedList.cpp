#include "linkedList.h"
#include <iostream>

using namespace std;

linkedList::linkedList() 
{
    first = NULL;
    last = NULL;
    count = 0;
}

void linkedList::insertLast(const Student& newItem)
{
  nodeType *newNode;       //pointer to create the new node
  newNode = new nodeType;  //create the new node
  newNode->info = newItem; //store the new item in the node
  newNode->link = NULL;    //set the link field of newNode to NULL
  
  if (first == NULL)       //if the list is empty, newNode is both the first and last node
    {
      first = newNode;
      last = newNode;
    }
  else //the list is not empty, insert newNode after last
    {
      last->link = newNode; //insert newNode after last
      last = newNode; //make last point to the actual last node in the list
    }

  count++; //increment count
}

Student linkedList::findStudent(const int id)
{
    nodeType *current; //pointer to traverse the list
    current = first;    //set current point to the first node
    Student tmpStudent;
    
    while (current != NULL)
    {
        if (current->info.id == id ) {
            tmpStudent = current->info;
            break;
        }
        current = current->link;
    }
    return tmpStudent;
}

int linkedList::getLength() const
{
   return count;
}
