#include <iostream>
#include <string>
#include "Roster.h"

using namespace std;

Roster::Roster () : allStudents(), cache()
{
}

linkedList* Roster::getAllStudents()
{
    return &allStudents;
}
hashTable* Roster::getCache()
{
    return &cache;
}

// DO NOT MODIFY ANYTHING ABOVE THIS LINE

void Roster::addStudent(const Student& newStudent )
{
   // implement this function
  allStudents.insertLast(newStudent);
  cache.insert(newStudent);

}

Student Roster::getStudent(const int id, bool& fromCache )
{
   // implement this function
  if(cache.check(id)) {
    fromCache = true;
    return cache.find(id);
  } else {
    fromCache = false;
    cache.insert(allStudents.findStudent(id));
    return allStudents.findStudent(id);
  }
}
