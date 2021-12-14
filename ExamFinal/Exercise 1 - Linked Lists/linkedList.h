#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

class Student {
public:
    string name;
    int id;
};

class nodeType
{
public:
    Student info;
    nodeType *next;
    nodeType *prev;
};


class linkedList {
public:
    int count;
    nodeType *first;
    nodeType *last;

    linkedList();
    int getLength() const;
    void printList() const;
    void insertLast(const Student& newItem);
    void deleteStudent (nodeType *student);
    void removeDuplicates();
};


#endif