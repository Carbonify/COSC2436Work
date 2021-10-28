#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "Student.h"

using namespace std;

// This is a simple hash table without
// any collision handling

#define EmptyID -1

class hashTable {
private: 
  int tableSize;
  Student *students;

public:
  hashTable(int _tableSize=10);
  ~hashTable();
  
  bool insert(const Student& newStudent);
  bool check ( const int id);
  Student find(const int id);
};

#endif

