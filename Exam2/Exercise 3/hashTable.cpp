#include <iostream>
#include "hashTable.h"

hashTable::hashTable ( int _tableSize )
{
    tableSize = _tableSize;
    students = new Student[tableSize];
    for ( int i=0; i< tableSize; i++ ) {
        students[i].id = EmptyID;        
    }
}

hashTable::~hashTable ()
{
    delete[] students;
}

bool hashTable::check ( const int id)
{
    int pos = id %tableSize;
    if ( students[pos].id  == id )
        return true;

    return false;
}

bool hashTable::insert ( const Student &newItem )
{
    int pos = newItem.id%tableSize;

    // overwrite current element in the hash table
    students[pos] = newItem;

    return true;
}

Student hashTable::find ( const int id )
{
    int pos = id%tableSize;
    return students[pos];
}
