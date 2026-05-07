/*
    Bank Queue System
    Data Structure: Queue (FIFO)
    push()        → O(1)  (Adding customer at rear)
    pop()         → O(1)  (Removing customer from front)
    front()       → O(1)  (Accessing current customer)
    display()     → O(n)  (Traversing all customers)

    SPACE COMPLEXITY: O(n) → Stores all customers in queue
*/

#include <iostream>
#include <queue>
using namespace std;

// Function to add customer
void addCustomer(queue<string>& q) {
    string name;
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name);

    if (name.empty()) {
        cout << "Invalid name!\n";
        return;
    }

    q.push(name);
    cout << name << " added to queue.\n";
}

// Function to serve customer
void serveCustomer(queue<string>& q) {
    if (q.empty()) {
        cout << "No customers in queue.\n";
        return;
    }

    cout << "Serving customer: " << q.front() << endl;
    q.pop();
}

// Function to show current customer
void showCurrent(queue<string>& q) {
    if (q.empty()) {
        cout << "No current customer.\n";
        return;
    }

    cout << "Current customer: " << q.front() << endl;
}

// Function to display full queue
void showQueue(queue<string> q) {
    if (q.empty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "\n===== Waiting List =====\n";

    int pos = 1;
    while (!q.empty()) {
        cout << pos << ". " << q.front() << endl;
        q.pop();
        pos++;
    }
}

int main() {
    queue<string> q;
    int choice;

    do {
        cout << "\n===== BANK QUEUE SYSTEM =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Show Waiting List\n";
        cout << "4. Show Current Customer\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addCustomer(q);
                break;

            case 2:
                serveCustomer(q);
                break;

            case 3:
                showQueue(q);
                break;

            case 4:
                showCurrent(q);
                break;

            case 5:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}


