#include "BucketNode.h"
#include "HashTable.h"
#include <cstdio>

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

//add password to correct bucket in hash table; also, indicate if password was from the actualPassword.txt file or attemptedPassword.txt file
void HashTable::addElement(string password, bool actualPassword) {
  BucketNode* newElement = new BucketNode();
  newElement->password = password;
  newElement->actualPassword = actualPassword;

  int hashLocation = hashFunc(password);
  HashBucket& insertBucket = bucketArray[hashLocation];

  if(! insertBucket.head) { //no existing element at location
    insertBucket.head = newElement;
  } else { //need to add to linked list
    BucketNode* iter = insertBucket.head;
    while(iter->next){ //move iter pointer to end of list
      iter = iter->next;
    }
    //add new element to the end of the chain
    newElement->prev = iter;
    iter->next = newElement;
  }
}

//print all nodes in buckets consisting of only one element, then delete that element
void HashTable::removeElements() {
  for(int i = 0; i < maxBuckets; i++) {
    if(numElementsInBucket(i) == 1) {
      printf("%s deleted\n", bucketArray[i].head->password.c_str());
      delete bucketArray[i].head;
      bucketArray[i].head = nullptr;
    }
  }
}

//print all compromised passwords
void HashTable::printCollisions() {
  int elementsFound;
  for(int i = 0; i < maxBuckets; i++){
    elementsFound = numElementsInBucket(i);
    if(elementsFound > 1) {
      printf("%s: %d collisions\n", bucketArray[i].head->password.c_str(), elementsFound);
    }
  }
}
