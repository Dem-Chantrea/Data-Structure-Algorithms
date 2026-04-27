#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int n = 5;
    int key;
	
	cout <<"Array :";
	for(int i=0;i<n; i++){
		cout << arr[i] << " ";
	}

    cout << "\nEnter value to search: ";
    cin >> key;

    int found = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1)
        cout << "Found at index " << found << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
