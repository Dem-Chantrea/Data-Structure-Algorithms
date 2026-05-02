#include <iostream>
#include <stack>
using namespace std;

/*
 * Problem: Check Balanced Parentheses
 * Approach: Stack (LIFO)
 * Time Complexity: O(n)
 */

bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expr) {
    stack<char> st;

    for (char c : expr) {

        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }

        // Check closing brackets
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || !isMatch(st.top(), c)) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string expr;

    cout << "Enter expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
