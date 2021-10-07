#include <cstdio>
#include "hashTable.h"

hashTable::hashTable ( int tableSize ): count(0)
{
  // implement constructor
  int fixedTableSize = (tableSize >= 1)? tableSize : 100;
  puppies = new Puppy[fixedTableSize];

  //set all puppies' age to -1, so we know when spots are empty
  for(int i = 0; i<fixedTableSize; i++) {
    puppies[i].age = -1;
  }
}

hashTable::~hashTable ()
{
  // implement destructor;
  delete[] puppies;
  puppies = nullptr;
}

int hashTable::length() const
{
  return count;
}

void hashTable::insert ( const Puppy &newItem )
{
  // implement function
  if(puppies[newItem.age].age != -1) { //valid insert
    puppies[newItem.age] = newItem;
  } else {
    printf("Slot %d already occupied, cannot add Puppy\n", newItem.age);
  }
}

void hashTable::printAll () const
{
  for ( auto i = 0; i < count; i++ ) {
    if ( puppies[i].age != -1 ) {
      printf("%s Age %d\n", puppies[i].name.c_str(), puppies[i].age);
    }
  }
}
