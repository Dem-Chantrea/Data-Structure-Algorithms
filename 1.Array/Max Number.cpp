#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 7, 2, 9, 1};
    int size = 5;

    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Max = " << max;
    return 0;
}
