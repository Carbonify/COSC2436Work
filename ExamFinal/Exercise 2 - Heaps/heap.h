#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

void maxHeapPercolateUp(int nodeIndex, int* heapArray) {
  while (nodeIndex > 0) {
    int parentIndex = (nodeIndex - 1) / 2;
    if (heapArray[nodeIndex] <= heapArray[parentIndex]) {
      return;
    } else {
      //swap heapArray[nodeIndex] and heapArray[parentIndex]
      int temp = heapArray[parentIndex];
      heapArray[parentIndex] = heapArray[nodeIndex];
      heapArray[nodeIndex] = temp;

      nodeIndex = parentIndex;
    }
  }
}

void heapify(int *data, int size)
{
  // Implement this function
  for(int i = 0; i < size; i++) {
    maxHeapPercolateUp(i, data);
  }
}

// DO NOT MODIFY CODE BELOW THIS LINE

bool is_maxheap ( int *data, int size, int pos=0 )
{
  int child1 = 2*pos+1;
  int child2 = 2*pos+2;
  bool b1=true, b2=true;
  bool result = true;

  if ( child1 < size ) {
    if  ( data[pos] < data[child1] || !is_maxheap(data, size, child1) ){
      b1 = false;
    }
  }
  if ( child2 < size ) {
    if ( data[pos] < data[child2] || !is_maxheap ( data, size, child2 ) ) {
      b2 = false;
    }
  }

  if ( !b1 || !b2 )
    result = false;

  return result;
}

void print_data(int *data, int size)
{
  cout << "    ";
  for ( int i=0; i<size; i++ ) {
    cout << data[i] << " ";
  }
  cout << std::endl;
}
#endif
