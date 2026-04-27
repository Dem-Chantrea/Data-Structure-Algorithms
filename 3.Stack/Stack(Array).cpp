#include <iostream>
using namespace std;

#define MAX 5

int stackArr[MAX];
int top = -1;

// Push
void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = value;
}

// Pop
void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << stackArr[top--] << endl;
}

// Peek
void peek() {
    if (top == -1) {
        cout << "Empty stack\n";
        return;
    }
    cout << "Top: " << stackArr[top] << endl;
}

// Display
void display() {
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << endl;
    }
}

// Main
int main() {
    push(10);
    push(20);
    push(30);

    display();
    peek();
    pop();
    display();
}
