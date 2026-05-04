#include <iostream>
using namespace std;

/*
 * Queue Implementation using Array (OOP)
 */

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    // Enqueue
    void enqueue(int value) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = value;
    }

    // Dequeue
    int dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    // Display
    void display() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

// Main
int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "After dequeue: ";
    q.display();

    return 0;
}
