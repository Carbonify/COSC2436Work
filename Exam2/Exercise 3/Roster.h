#ifndef __ROSTER_H__
#define __ROSTER_H__


#include <string>
#include "Student.h"
#include "linkedList.h"
#include "hashTable.h"


class Roster {
private:
    linkedList allStudents;
    hashTable  cache;

public:
    Roster();
    linkedList* getAllStudents();
    hashTable*  getCache();

    void addStudent(const Student& newStudent);
    Student getStudent (const int id, bool& fromCache);
};

#endif
