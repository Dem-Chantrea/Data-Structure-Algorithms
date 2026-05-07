// Merge Sort
// Idea: Divide array into halves, then merge sorted parts
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <iostream>
using namespace std;

// Merge two sorted parts of the array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // size of left part
    int n2 = right - mid;      // size of right part

    int* L = new int[n1];      // temp left array
    int* R = new int[n2];      // temp right array

    // copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // merge temp arrays back into original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // remaining elements
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;  // free memory
    delete[] R;
}

// Recursive merge sort
void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;  // base case

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);      // sort left half
    mergeSort(arr, mid + 1, right); // sort right half

    merge(arr, left, mid, right);   // merge both halves
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int n = 5;

    cout << "Before: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After: ";
    printArray(arr, n);

    return 0;
}
