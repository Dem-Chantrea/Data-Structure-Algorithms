#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 7, 2, 9, 1,10,0,5};
    int size = 8;


    int min = arr[0];

	for (int i = 1; i < size; i++) {
	    if (arr[i] < min) {
	        min = arr[i];
	    }
	}

    cout << "Min = " << min;
    return 0;
}
