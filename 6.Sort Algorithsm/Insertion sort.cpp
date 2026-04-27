#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[5] = {5, 2, 9, 1, 3};
    int n = 5;

    cout << "Before Sorting: ";
    printArray(arr, n);

    // ?? Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // shift right
            j--;
        }

        arr[j + 1] = key; // insert
    }

    cout << "After Sorting: ";
    printArray(arr, n);

    return 0;
}
