#ifndef STACK_H
#define STACK_H

class Stack {
private:
    char data[10];  
    int top;

public:
    Stack();

    bool push(char x);
    bool pop(char &x);
    bool getTop(char &x);  
    bool isEmpty();
    bool isFull();
};

#endif