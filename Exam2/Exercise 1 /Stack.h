#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    char *list;
    int maxStackSize;
    int stackTop;

public:
    Stack(int n = 100);
    void push(const char input);
    char pop();
    bool isEmpty() const;
    ~Stack();

};

#endif