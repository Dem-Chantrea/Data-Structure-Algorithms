#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 7, 2, 9, 1};
    int size = 5;
   	int sum = 0;

	for (int i = 0; i < size; i++) {
	    sum += arr[i];
	}

    cout << "Sum = " << sum;
    return 0;
}
