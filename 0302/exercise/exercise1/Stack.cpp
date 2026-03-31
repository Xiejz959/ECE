#include "Stack.h"

Stack::Stack() {
    top = -1;
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == 9;
}

bool Stack::push(char x) {
    if (isFull()) return false;
    data[++top] = x;
    return true;
}

bool Stack::pop(char &x) {
    if (isEmpty()) return false;
    x = data[top--];
    return true;
}

bool Stack::getTop(char &x) {
    if (isEmpty()) return false;
    x = data[top];
    return true;
}