#include <iostream>
#include <cctype>
#include "Stack.h"

using namespace std;

//priority
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    Stack s;
    char expr[20];
    char output[20];
    int k = 0;

    cout << "input the infix expression" << endl;
    cin.getline(expr, 20);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // number direct
        if (isdigit(ch)) {
            output[k++] = ch;
        }
        // left in stack
        else if (ch == '(') {
            s.push(ch);
        }
        // right wait until left
        else if (ch == ')') {
            char topChar;
            while (!s.isEmpty()) {
                s.pop(topChar);
                if (topChar == '(') break;
                output[k++] = topChar;
            }
        }
        // sign
        else {
            char topChar;
            while (!s.isEmpty()) {
                s.getTop(topChar);
                if (priority(topChar) >= priority(ch)) {
                    s.pop(topChar);
                    output[k++] = topChar;
                } else break;
            }
            s.push(ch);
        }
    }

    // pop everything
    char topChar;
    while (!s.isEmpty()) {
        s.pop(topChar);
        output[k++] = topChar;
    }

    output[k] = '\0';

    cout << "postfix expression: " << output << endl;

    return 0;
}