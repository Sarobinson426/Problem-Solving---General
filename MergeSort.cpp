#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void merge(int* arr, int begin, int middle, int end);
void merge_sort(int* arr, int begin, int end);

int main()
{
	// e.g. of an array
	int arr[11] = { 100, 50, 25, 75, 30, 33, 29, 22, 89, 11 };
	int size;

	// can use for more dynamic arrays to get an exact size for the array
	// works with other datatypes arrays as well
	size = sizeof(arr) / sizeof(arr[0]);

	cout << "Before" << endl;
	for (int x = 0; x < size; x++) {
		cout << arr[x] << endl;
	}

	merge_sort(arr, 0, 10);

	cout << "\nAfter" << endl;
	for (int x = 0; x < size; x++) {
		cout << arr[x] << endl;
	}

	return 0;
}

void merge(int* arr, int begin, int middle, int end) {
	int low = begin;
	int c = begin;
	int mid = middle + 1;
	int temp[11] = { 0 };

	// move through array while low is less than the middle (parameter) and mid (declared in function) is less than end
	// assign either arr[low/mid] to temp array and advance low/mid and temp[] position
	while (low <= middle && mid <= end) {
		if (arr[low] < arr[mid]) {        // compare
			temp[c++] = arr[low++];       // assign if arr[low] is lower
		}
		else {
			temp[c++] = arr[mid++];       // assign if arr[mid] is lower
		}
	}

	// if either low or mid reach end then fill rest of array with remaining values
	// either low/mid will have already reached the it's stop point in the above 
	// while loop  so only one or the other of these while loops will run
	while (low <= middle) {
		temp[c++] = arr[low++];       // "fill" rest of temp array with lower half of array
	}
	while (mid <= end) {
		temp[c++] = arr[mid++];       // "fill" rest of temp array with upper half of array
	}

	for (low = begin; low < c; low++) {  // since no return type and passed in by reference 
		arr[low] = temp[low];            // assign all temp array values to the array passed in 
	}
}

void merge_sort(int* arr, int begin, int end) {
	int middle;

	// base case as long as begin is less than end 
	// middle/middle + 1 serves as the begin of one array half and the end of the other
	if (begin < end) {
		middle = (begin + end) / 2;

		merge_sort(arr, middle + 1, end); // last half of divide and conquer
		merge_sort(arr, begin, middle);   // first half of divide and conquer

		merge(arr, begin, middle, end);   // comparisons and assignments made in this function
	}
}
