/* Circle QUEUE
    
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* q;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        q = new int[capacity];
        front = -1;
        rear = -1;
    }

//Enqueue
    void enqueue(int value) {
        if ((rear + 1) % capacity == front) {
            cout << "Queue FULL\n";
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        q[rear] = value;
        cout << "Inserted: " << value << endl;
    }

//Dequeue
    void dequeue() {
        if (front == -1) {
            cout << "Queue EMPTY\n";
            return;
        }

        cout << "Removed: " << q[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

//Display
    void display() {
        if (front == -1) {
            cout << "Queue EMPTY\n";
            return;
        }

        cout << "Queue: ";
        int i = front;

        while (true) {
            cout << q[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }

        cout << endl;
    }

    ~CircularQueue() {
        delete[] q;
    }
};

//Main
int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
