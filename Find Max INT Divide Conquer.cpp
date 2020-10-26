//Author: Shaun Robinson
//Program: Divide Conquer Max Value
//Description: Finds the max int value of an int array using divide and conquer

#include<iostream>
#include<ctime>
using namespace std;

int max_value(int start, int end, int arr[]) {
	if (start == end) {
		return arr[start];
	}
	else {
		int mid = (start + end) * 0.5;
		int left = max_value(start, mid, arr);
		int right = max_value(mid + 1, end, arr);
		if (left > right) {
			return left;
		}
		else {
			return right;
		}
	}
}

int main() {
	int random_num, num_array[1000], result;

	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		random_num = rand();
		num_array[i] = random_num;
	}

	result = 0;
	result = max_value(0, 1000, num_array);

	cout << "Maximum Value: " << result << endl;

	cout << "Array Start" << endl;
	for (int i = 0; i < 1000; i++) {
		cout << num_array[i] << " ";
	}
	cout << "\nArray End" << endl;

	return 0;
}