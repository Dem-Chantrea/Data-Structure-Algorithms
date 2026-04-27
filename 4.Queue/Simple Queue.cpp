#include <iostream>
using namespace std;

#define MAX 5

int queueArr[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1) front = 0;

    queueArr[++rear] = value;
    cout <<endl;
}

// Dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }

    cout << "Removed: " << queueArr[front++] << endl;
}

// Display
void display() {
    if (front == -1 || front > rear) {
        cout << "Empty queue\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

// Main
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();
}
