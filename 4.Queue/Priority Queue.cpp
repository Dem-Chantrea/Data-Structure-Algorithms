/* 
Task Scheduler using Priority Queue
 Data Structure: priority_queue
 Time Complexity:
   Insert: O(log n)
   Remove: O(log n)
Key Concept:
- A Priority Queue is a data structure where each element is assigned a priority.
- The element with the highest (or lowest) priority is removed first, not based on insertion order.

Conditions:
- Empty → pq.empty()
- No fixed full condition (dynamic size, grows automatically)
*/

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
