#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);

    cout << "Deque: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "After removal: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }

    return 0;
}
