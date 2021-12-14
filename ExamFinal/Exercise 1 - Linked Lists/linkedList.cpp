#include <iostream>
#include "linkedList.h"

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
  newNode->prev = NULL;    //set the link field of newNode to NULL
  newNode->next = NULL;    //set the link to prev. node to NULL

  if (first == NULL)       //if the list is empty, newNode is both the first and last node
    {
      first = newNode;
      last = newNode;
    }
  else //the list is not empty, insert newNode after last
    {
      last->next = newNode;
      newNode->prev = last;
      last = newNode;
    }

  count++; //increment count
}

int linkedList::getLength() const
{
  return count;
}

void linkedList::printList() const
{
  nodeType *current=first;
  while (current != nullptr ) {
    cout << "Student " << current->info.name << " ID " << current->info.id << endl;
    current = current->next;
  }
}


void linkedList::deleteStudent (nodeType* student)
{
  // Implement this function
  if(student == first) {
    first = student->next;
  }
  if(student == last) {
    last = student->prev;
  }
  if(student->prev) {
    student->prev->next = student->next;
  }
  if(student->next) {
    student->next->prev = student->prev;
  }
  delete student;
  count--;
}

void linkedList::removeDuplicates()
{
  // Implement this function
  nodeType* iter1 = first;
  nodeType* iter2;
  while(iter1) {
    iter2 = first->next;
    while(iter2) {
      if(iter1->info.name == iter2->info.name
         && iter1->info.id == iter2->info.id
         && iter1 != iter2) {
        deleteStudent(iter2);
      }
      iter2 = iter2->next;
    }
    iter1 = iter1->next;
  }
}
