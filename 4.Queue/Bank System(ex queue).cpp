#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;
    int choice;
    string name;

    do {
        cout << "\n===== BANK QUEUE SYSTEM =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Show Waiting List\n";
        cout << "4. Show Current Customer\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

            case 1:
                cout << "Enter customer name: ";
                getline(cin, name);
                q.push(name);
                cout << name << " added to queue\n";
                break;

            case 2:
                if (q.empty()) {
                    cout << "No customers in queue\n";
                } else {
                    cout << "Serving: " << q.front() << endl;
                    q.pop();
                }
                break;

            case 3:
                if (q.empty()) {
                    cout << "Queue is empty\n";
                } else {
                    cout << "Waiting List: ";
                    queue<string> temp = q;

                    while (!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 4:
                if (!q.empty())
                    cout << "Current Customer: " << q.front() << endl;
                else
                    cout << "No current customer\n";
                break;

            case 5:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
