/*
    Program: Sorting + Binary Search
    --------------------------------
    - Uses STL sort (O(n log n))
    - Uses Binary Search (O(log n))
    - Total Complexity: O(n log n)

    Concepts:
    - Efficient sorting
    - Divide and conquer search
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Binary Search Function
int binarySearch(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        // Prevent overflow
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Not found
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 3};
    int key;

    // Display original array
    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";

    // Efficient Sorting (O(n log n))
    sort(arr.begin(), arr.end());
    cout << "\nSorted Array: ";
    for (int num : arr)
        cout << num << " ";

    // Input value to search
    cout << "\nEnter value to search: ";
    cin >> key;

    // Perform binary search
    int index = binarySearch(arr, key);

    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
