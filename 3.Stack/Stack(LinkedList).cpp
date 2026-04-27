#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

// Push
void push(int value) {
    Node* newNode = new Node{value, top};
    top = newNode;
}

// Pop
void pop() {
    if (!top) {
        cout << "Underflow\n";
        return;
    }
    Node* temp = top;
    cout << "Popped: " << temp->data << endl;
    top = top->next;
    delete temp;
}

// Peek
void peek() {
    if (!top) {
        cout << "Empty\n";
        return;
    }
    cout << "Top: " << top->data << endl;
}

int main() {
    push(5);
    push(10);
    push(15);

    peek();
    pop();
    peek();
}
