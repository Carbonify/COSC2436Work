#include "BucketNode.h"
#include "HashTable.h"
#include <iostream>

HashTable::HashTable() {
  bucketArray = new HashBucket[10];
  maxBuckets = 10;
}

HashTable::~HashTable() {
  //free memory related to the table
  delete[] bucketArray;
  bucketArray = nullptr;
}

int HashTable::hashFunc(string password) {
  int hashval = 0;
  for (unsigned int i = 0; i < password.size(); i++) {
    hashval = hashval + ((char)password[i]);
  }
  hashval = hashval % 10;
  return hashval;
}

int HashTable::numElementsInBucket(int bucketIndex) {
  //return number of passwords in specified bucket of hash table

  BucketNode* iter = bucketArray[bucketIndex].head;
  int entries = 0;

  while(iter) {
    iter = iter->next;
    entries++;
  }
  return entries;
}

void HashTable::addElement(string password, bool actualPassword) {
  //add password to correct bucket in hash table; also, indicate if password was from the actualPassword.txt file or attemptedPassword.txt file
}

void HashTable::removeElements() {
  //print all nodes in buckets consisting of only one element, then delete that element
}

void HashTable::printCollisions() {
  //print all compromised passwords
}
