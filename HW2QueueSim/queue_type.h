#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

#include <iostream>
#include <cassert>
#include <iostream>

#include "queueADT.h"

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
  //the implementation of these funcs should really be seperated out into
  //a cpp file, with just the declarations here, but eh
public:
	queueType(int queueSize = 100)
  {
    maxQueueSize = (queueSize > 1)? queueSize : 100;
    count = 0;
    queueFront = 0;
    queueRear = 0;
    list = new Type[queueSize];

  }

	~queueType() {
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

	void initializeQueue(); //unused? can be done in constructor


	Type front() const {
		assert(!isEmptyQueue());
		return list[queueFront];
	}

	Type back() const {
		assert(!isEmptyQueue());
		return list[queueRear];
	}

	void enQueue(const Type& queueElement) {

    // implement function
    if(count >= maxQueueSize) {
      std::cout << "Can not add to a full queue" << std::endl;
    } else {
      list[queueRear] = queueElement;
      queueRear = (queueRear + 1) % maxQueueSize; //wraps around back to 0 if we've hit the end of the array
    }
	}

	void deQueue() {
    // implement function
	}


private:
	int maxQueueSize; //variable to store the maximum queue size
	int count; //variable to store the number of
	int queueFront; //variable to point to the first
	int queueRear; //variable to point to the last
	Type* list; //pointer to the array that holds
};

#endif // !QUEUE_TYPE_H
