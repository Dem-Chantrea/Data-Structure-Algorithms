#include <iostream>
using namespace std;

/*
 * Stack Implementation using Linked List (OOP Version)
 */

class Stack {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = NULL;
        }
    };

    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop
    int pop() {
        if (!top) {
            cout << "Stack Underflow\n";
            return -1;
        }

        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;

        return value;
    }

    // Peek
    int peek() {
        if (!top) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    // Display
    void display() {
        if (!top) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // Destructor 
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main() {
    Stack s;

    s.push(5);
    s.push(10);
    s.push(15);

    cout << "Top: " << s.peek() << endl;

    cout << "Popped: " << s.pop() << endl;

    cout << "After pop:\n";
    s.display();

    return 0;
}
