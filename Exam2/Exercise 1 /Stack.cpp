#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(int n)
{
    maxStackSize = n;

    if(maxStackSize < 0)
        maxStackSize = 100;

    list = new char[maxStackSize];
    stackTop = 0;
}

void Stack::push(const char input)
{
    if(stackTop == maxStackSize)
        cout << "Can not push in a full stack." << endl;
    else
        list[stackTop++] = input;
}

char Stack::pop()
{
    if(stackTop == 0) {
        cout << "Can not pop from an empty stack." << endl;
        return '0';
    }
    else
        stackTop--;

    return list[stackTop];
}


bool Stack::isEmpty() const
{
    return stackTop==0;
}

Stack::~Stack()
{
    delete [] list;
}