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

  //copy constructor, copies and condenses the queue to start at 0
  queueType(const queueType& other) {
    initializeQueue();

    //sync list sizes
    list = new Type[other.maxQueueSize];
    maxQueueSize = other.maxQueueSize;

    //we start writing at position 0
    //we want to condense this new queue so it starts from 0 rather than an arbitrary location
    int writePosition = 0;

    //Iterate through other, starting at the front of other's queue and going until we hit
    //other's queueRear - i must wrap around to 0 upon hitting the end of the array, because
    //queueRear could be ahead of queueFront.
    for(int i = other.queueFront; i <= other.queueRear; i = (i+1) % maxQueueSize) {
      list[writePosition] = other.list[i];
      writePosition++;
    }
    //new rear is wherever we reached while writing, -1 because we go one farther than we need to
    //and queuerear should point to the actual rear element's index
    queueRear = writePosition-1;
    count = other.count; //sync count, as that hasn't changed
  }

  void printQueue() {
    for(int i = queueFront; i <= queueRear; i = (i+1) % maxQueueSize) {
      std::cout << "[" << i << "] " << list[i] << std::endl;
    }
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
      printf("Can not add to a full queue\n");
    } else {
      if(!isEmptyQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize; //wraps around back to 0 if we've hit the end of the array
      }

      list[queueRear] = queueElement;
      count++;
      printf("New client added. Queue now has %d clients.\n", count);
    }
  }

  void deQueue() {
    if(isEmptyQueue()) {
      printf("Cannot remove from an empty queue\n");
    } else if (count == 1) { //removing last element of list
      initializeQueue();

      printf("Client removed from queue. Queue now has %d clients.\n", count);
    } else {
      queueFront = (queueFront + 1) % maxQueueSize; //wraps around back to 0 if we've hit the end of the array
      count--;
      printf("Client removed from queue. Queue now has %d clients.\n", count);
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
