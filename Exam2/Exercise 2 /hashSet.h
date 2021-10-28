#ifndef HASHSET_H
#define HASHSET_H

#include <string>
#include "Student.h"

using namespace std;

#define EmptyID -1

class hashSet {
private:
    int tableSize;
    int setSize;
    Student **students;

public:
    hashSet(int _tableSize=10, int _setSize=2 );
    ~hashSet();
    int length() const;
    bool insert(const Student& newStudent);
    Student getStudent(const int id);
};


#endif