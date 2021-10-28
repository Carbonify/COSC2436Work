#include <iostream>
#include "Student.h"
#include "hashSet.h"

hashSet::hashSet ( int _tableSize, int _setSize)
{
  tableSize = _tableSize;
  setSize = _setSize;
  students = new Student*[tableSize];
  for ( int i=0; i< tableSize; i++ ) {
    students[i] = new Student[setSize];
  }

  for ( int i=0; i< tableSize; i++ ) {
    for ( int j=0; j < setSize; j++ ) {
      students[i][j].id = EmptyID;
    }
  }
}

hashSet::~hashSet ()
{
  for ( int i=0; i < tableSize; i++ ) {
    delete[] students[i];
  }

  delete[] students;
}

int hashSet::length() const
{
  return tableSize;
}

bool hashSet::insert ( const Student &newItem )
{
  // implement this function
  int hash = newItem.id % tableSize;
  for(int i = 0; i<setSize; i++) {
    if(students[hash][i].id == EmptyID) {
      students[hash][i].id = newItem.id;
      students[hash][i].name = newItem.name;
      return true;
    }
  }
  return false;
}

Student hashSet::getStudent ( const int id )
{
  // implement this function
  int hash = id % tableSize;

  for(int i = 0; i<setSize; i++) {
    if(students[hash][i].id == id) {
      return students[hash][i];
    }
  }
  cout << "Could not find student with id " << id << " in hashSet" << endl;
  return Student();
}
