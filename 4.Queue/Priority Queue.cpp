#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Task {
    string name;
    int priority;
};

// Comparator
struct Compare {
    bool operator()(Task a, Task b) {
        return a.priority < b.priority; // higher priority first
    }
};

int main() {
    priority_queue<Task, vector<Task>, Compare> pq;

    int n;
    cout << "Enter number of tasks: ";
    cin >> n;
    cin.ignore(); // clear buffer

    // Input tasks
    for (int i = 0; i < n; i++) {
        Task t;

        cout << "\nEnter task name: ";
        getline(cin, t.name);

        cout << "Enter priority: ";
        cin >> t.priority;
        cin.ignore();

        pq.push(t);
    }

    // Display tasks by priority
    cout << "\n--- Task Execution Order ---\n";

    while (!pq.empty()) {
        Task t = pq.top();
        cout << t.name << " (Priority: " << t.priority << ")\n";
        pq.pop();
    }

    return 0;
}
