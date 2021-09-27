#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

#include <iostream>
#include <cstdio>
#include <cassert>

#include "queueADT.h"

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
public:
  queueType(int queueSize = 100)
  {
    maxQueueSize = (queueSize > 1)? queueSize : 100;
    initializeQueue();
    list = new Type[maxQueueSize];
  }


  ~queueType() {
    delete[] list;
    list = nullptr;
  }

  bool isEmptyQueue() const {
    return (count == 0);
  }

  bool isFullQueue() const {
    return (count == maxQueueSize);
  }

  int getSize() const {
    return count;
  }

  int getMaxCapacity() const {
    return maxQueueSize;
  }

  //resets numerical values to 0, does not reallocate list
  void initializeQueue() {
    count = 0;
    queueFront = 0;
    queueRear = 0;
  }


  Type front() const {
    assert(!isEmptyQueue());
    return list[queueFront];
  }

  Type back() const {
    assert(!isEmptyQueue());
    return list[queueRear];
  }

  void enQueue(const Type& queueElement) {
    if(count >= maxQueueSize) { //queue full
      printf("Can not add to a full queue");
    } else {
      if(!isEmptyQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize; //wraps around back to 0 if we've hit the end of the array
      }

      list[queueRear] = queueElement;
      count++;
      printf("New client added. Queue now has %d clients.", count);
    }
  }

  void deQueue() {
    if(isEmptyQueue()) {
      printf("Cannot remove from an empty queue");
    } else if (count == 1) { //removing last element of list
      initializeQueue();

      printf("Client removed from queue. Queue now has %d clients.", count);
    } else {
      queueFront = (queueFront + 1) % maxQueueSize; //wraps around back to 0 if we've hit the end of the array
      count--;
      printf("Client removed from queue. Queue now has %d clients.", count);
    }
    //should really return the dequeued element, but....
  }


private:
  int maxQueueSize; //variable to store the maximum queue size
  int count; //variable to store the number of elements
  int queueFront; //variable to point to the first element
  int queueRear; //variable to point to the last element
  Type* list; //pointer to the array that holds the queue
};

#endif // !QUEUE_TYPE_H
