#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Student.h"

using namespace std;

class nodeType
{
public:
    Student info;
    nodeType *link;
};


class linkedList {
private: 
    int count;
    nodeType *first;
    nodeType *last;
public:
    linkedList();
    int getLength() const;
    void insertLast(const Student& newItem);
    Student findStudent( const int id);
};


#endif

