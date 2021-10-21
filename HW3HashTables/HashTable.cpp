#include "BucketNode.h"
#include "HashTable.h"
#include <cstdio> //for printf

HashTable::HashTable() {
  maxBuckets = 10;
  bucketArray = new HashBucket[maxBuckets];
}

HashTable::~HashTable() {
  //free memory in each bucket
  for(int i = 0; i < maxBuckets; i++) {
    BucketNode* iter = bucketArray[i].head;
    while(iter) {
      BucketNode* iterNext = iter->next;
      delete iter;
      iter = iterNext;
    }
  }
  //free memory related to the table
  delete[] bucketArray;
  bucketArray = nullptr;
}

int HashTable::hashFunc(const string password) {
  int hashval = 0;
  for (unsigned int i = 0; i < password.size(); i++) {
    hashval = hashval + ((char)password[i]);
  }
  return hashval % 10;
}

int HashTable::numElementsInBucket(const int bucketIndex) {
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
void HashTable::addElement(const string password, const bool actualPassword) {
  BucketNode* newElement = new BucketNode();
  newElement->password = password;
  newElement->actualPassword = actualPassword;

  //determine bucket to insert new entry into
  HashBucket& insertBucket = bucketArray[hashFunc(password)];

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
    BucketNode* bucketHead = bucketArray[i].head;

    if(elementsFound > 1 && bucketHead->actualPassword) { //if collisions exist and password is real
      printf("%s: %d collisions\n", bucketHead->password.c_str(), elementsFound - 1);
    }
  }
}
