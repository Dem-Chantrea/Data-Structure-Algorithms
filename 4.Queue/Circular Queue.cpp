#include <iostream>
using namespace std;

#define MAX 5

int q[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        cout << "Queue FULL\n";
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    q[rear] = value;
    cout << "Inserted: " << value << endl;
}

// Dequeue
void dequeue() {
    if (front == -1) {
        cout << "Queue EMPTY\n";
        return;
    }

    cout << "Removed: " << q[front] << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
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

        i = (i + 1) % MAX;
    }

    cout << endl;
}

// Main
int main() {
    int choice, value;

    do {
        cout << "\n--- Circular Queue ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid\n";
        }

    } while (choice != 4);

    return 0;
}
