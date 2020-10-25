//Author: Shaun Robinson
//Program: Find Max
//Description: find maximum value in an array 
//Input: user inputs a number to find
//Output: int value of number or string stating 'not found'
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int find_max(int size, const int num_array[]) {
	if (size == 1) {
		return num_array[0];
	} 
	else {
		int max = find_max(size - 1, num_array);
		if (max > num_array[size - 1]) {
			return max;
		}
		else {
			return num_array[size - 1];
		}
	}
}

int main() {
	int random_num, num_array[100], result;

	srand(time(0));
	for (int i = 0; i < 100; i++) {
		random_num = rand();
		num_array[i] = random_num;
	}

	result = 0;
	result = find_max(100, num_array);

	cout << result << endl;

	for (int i = 0; i < 100; i++) {
		cout << num_array[i] << " ";
	}

	return 0;
}