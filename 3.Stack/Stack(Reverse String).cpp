#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> st;
    string str;

    cout << "Enter string: ";
    getline(cin, str);

    // Push all characters
    for (int i = 0; i < str.length(); i++) {
    st.push(str[i]);
}
    }
    
	//pop
	string reversed = "";
	while (!st.empty()) {
	    reversed += st.top();
	    st.pop();
	}

    cout << "Reversed: " << reversed << endl;

    return 0;
}
