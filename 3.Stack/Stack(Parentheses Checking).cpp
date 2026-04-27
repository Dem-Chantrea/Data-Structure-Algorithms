#include <iostream>
#include <stack>
using namespace std;

// Check matching pair
bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    stack<char> st;
    string expr;

    cout << "Enter expression: ";
    getline(cin, expr);

    bool valid = true;

    for (char c : expr) {
        // Opening bracket
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // Closing bracket
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || !isMatch(st.top(), c)) {
                valid = false;
                break;
            }
            st.pop();
        }
    }

    if (!st.empty()) valid = false;

    if (valid)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
