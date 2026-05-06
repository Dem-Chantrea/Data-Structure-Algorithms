/*
 * Stack Implementation using Array (OOP Version)
 * Features:
 * - Push
 * - Pop
 * - Peek
 * - Display
 */

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Push
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek
    int peek() {
        if (top == -1) {
            cout << "Empty Stack\n";
            return -1;
        }
        return arr[top];
    }

    // Display
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    ~Stack() {
        delete[] arr;
    }
};
int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack elements:\n";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped: " << s.pop() << endl;

    cout << "After pop:\n";
    s.display();

    return 0;
}
