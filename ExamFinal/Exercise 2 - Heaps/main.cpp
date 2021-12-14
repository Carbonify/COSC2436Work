#include <iostream>
#include "heap.h"

using namespace std;

int main ( int argc, char **argv)
{
    int data[20] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21, 62, 27, 90, 59, 63, 26, 40, 26, 72, 36};
    heapify(data, 20);
    cout << "Array 1 is_maxheap returned " << is_maxheap(data, 20) << endl;

    return 0;
}
