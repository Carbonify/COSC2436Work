#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

#include <iostream>
#include <cassert>

#include "queueADT.h"

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
  //the implementation of these funcs should really be separated out into
  //a cpp file, with just the declarations here, but eh
public:
	queueType(int queueSize = 100)
  {
    maxQueueSize = (queueSize > 1)? queueSize : 100;
    count = 0;
    queueFront = 0;
    queueRear = 0;
    list = new Type[maxQueueSize];

  }

	~queueType() {
    //All other members are on stack and will be auto-freed
    delete[] list;
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

	void initializeQueue() {} //Unused, but must be declared because C++


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
      std::cout << "Can not add to a full queue" << std::endl;
    } else {
      list[queueRear] = queueElement;
      queueRear = (queueRear + 1) % maxQueueSize; //wraps around back to 0 if we've hit the end of the array
      count++;
      std::cout << "New client added. Queue now has " << count << " clients." << std::endl;
    }
	}

	void deQueue() {
    if(count == 0) {
      std::cout << "Cannot remove from an empty queue" << std::endl;
    } else {
      queueFront = (queueFront + 1) % maxQueueSize; //wraps around back to 0 if we've hit the end of the array
      count--;
      std::cout << "Client removed from queue. Queue now has " << count << " clients." << std::endl;
      //should really return the dequeued element, but....
    }
	}


private:
	int maxQueueSize; //variable to store the maximum queue size
	int count; //variable to store the number of elements
	int queueFront; //variable to point to the first element
	int queueRear; //variable to point to the last element
	Type* list; //pointer to the array that holds the queue
};

#endif // !QUEUE_TYPE_H
