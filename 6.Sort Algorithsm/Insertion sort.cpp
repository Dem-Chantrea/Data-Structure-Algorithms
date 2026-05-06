// Insertion Sort
// Idea: Insert each element into its correct position
// Time Complexity: O(n^2) worst, O(n) best
// Space Complexity: O(1)

#include <iostream>
using namespace std;

// Print array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // Initialize array
    int arr[5] = {5, 2, 9, 1, 3};
    int n = 5;

    cout << "Before Sorting: ";
    printArray(arr, n);

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];     // current element
        int j = i - 1;        // previous index

        // shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // insert element at correct position
        arr[j + 1] = key;
    }

    cout << "After Sorting: ";
    printArray(arr, n);

    return 0;
}
