#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

#include <iostream>
#include <cassert>
#include "queueADT.h"

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
public:
	queueType(int queueSize = 100) {
   // implement constructor
	}

	~queueType() {
	// implement destructor
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

	void initializeQueue() {
   // implement function
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
   // implement function
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