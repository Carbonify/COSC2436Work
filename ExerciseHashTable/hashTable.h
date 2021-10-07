#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

class Puppy {
public: 
  string name;
  string breed;
  int age=-1;
};


class hashTable {
private: 
  int count;
  Puppy *puppies;

public:
  hashTable(int tableSize=10);
  ~hashTable();
  int length() const;
  void insert(const Puppy& newItem);
  void printAll() const;
};


#endif

