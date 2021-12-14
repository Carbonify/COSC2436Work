#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    //use this code for test case or change for your own testing
    binaryTree test;

    test.insert(20);
    test.insert(25);
    test.insert(8);
    test.insert(4);
    test.insert(22);
    test.insert(11);

    bool result = test.isFull();
    if ( result == true )
        cout << "This tree is full\n";
    else
        cout << "This tree is not full\n";

    return 0;
}