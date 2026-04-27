#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 3}; // MUST be sorted
    int n = 5;
    int key;

    
    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {

            if (arr[j] > arr[j+1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    }
	
    cout << "\nSorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << "\nEnter value to search: ";
    cin >> key;

    int left = 0, right = n - 1;
    int found = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (found != -1)
        cout << "Found at index " << found << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
