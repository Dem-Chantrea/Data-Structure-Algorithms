#include <iostream>
using namespace std;

int main() {
    
    int arr[] = {1, 3, 5, 9, 10,7,2,8};
    int size = 8;

    int max = arr[0];
    int min = arr[0];
    int sum = 0;


    for (int i = 0; i < size; i++) {
        //  max
        if (arr[i] > max) {
            max = arr[i];
        }

        //  min
        if (arr[i] < min) {
            min = arr[i];
        }

        //  sum
        sum += arr[i];
    }

    //  Calculate average
    double avg = (double)sum / size;

    //  Search for a number
    int target = 9;
    int index = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }

    //  Display results
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;

    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found" << endl;

    //  Reverse array
    cout << "Reversed array: ";
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }

    return 0;
}
