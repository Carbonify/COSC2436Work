#include <iostream>
#include "hashTable.h"

hashTable::hashTable ( int tableSize )
{
  // implement constructor

}

hashTable::~hashTable ()
{
  // implement destructor;
}

int hashTable::length() const
{
  return count;
}

void hashTable::insert ( const Puppy &newItem )
{
  // implement function
}

void hashTable::printAll () const
{
  for ( auto i = 0; i < count; i++ ) {
    if ( puppies[i].age != -1 ) {
      std::cout << puppies[i].name << " Age " << puppies[i].age << endl;
    }
  }
}
