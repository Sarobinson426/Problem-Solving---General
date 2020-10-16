// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW10 Q3
// Program: Vectors Hard Way Vector Easy Way
// Input: user inputs a sequence numbers seperated by "enter" 
// Input: user also inputs a number to find from the input numbers
// Output: locations in the array where the number is in the input sequence
// Description: 

#include <iostream>
#include <vector>
using namespace std;

int* make_num_arr(int& num_nums);

vector<int> make_num_arr2();

void find_num(int* num_arr, int arr_size);

int main1(); //vector from scratch logical and physical size
int main2(); //vector from standard library 

int main() {
	main1();
}

int main1() {
	int* out_number = NULL, num_input;

	num_input = 0;
	out_number = make_num_arr(num_input); //function to create a vector and stores in int pointer out_number

	for (int i = 0; i < num_input; i++) {
		cout << out_number[i] << " ";
	}
	cout << endl;
	find_num(out_number, num_input); 

	delete[] out_number;

	return 0;
}
int main2() {
	vector<int> out_number;

	out_number = make_num_arr2();

	for (int i = 0; i < out_number.size(); i++) {
		cout << out_number[i] << " ";
	}
	cout << endl;

	int find_num;

	cout << "Enter a number you wish to search: ";
	cin >> find_num;

	cout << find_num << " is present in the array at: ";
	for (int index = 0; index < out_number.size(); index++) {
		if (find_num == out_number[index]) {
			cout << (index + 1) << " ";
		}
	}

	return 0;
}

int* make_num_arr(int& num_nums) {
	int* num_arr = NULL, * expand_num_arr = NULL, input_num, logical_size, physical_size;
	bool am_exiting;

	cout << "Enter numbers into an array -1 to exit: ";

	num_arr = new int[1];   // dynamic array
	logical_size = 0; // position in the array starts 0 and expands x2 each time logical_size == physical_size
	physical_size = 1; // the physical amount of bytes being used (4 bytes for int) increases when logical_size == physical_size

	am_exiting = false;
	while (am_exiting == false) {
		cin >> input_num;
		if (input_num == -1) {
			am_exiting = true;
		}
		else {
			if (logical_size == physical_size) {
				expand_num_arr = new int[2 * physical_size];
				for (int i = 0; i < logical_size; i++) {
					expand_num_arr[i] = num_arr[i];
				}
				delete[] num_arr;
				num_arr = expand_num_arr;
				physical_size *= 2;           // x2 physcial size i.e. from 1 to 2 to 4 to 8 to 16.... 
			}
			num_arr[logical_size] = input_num; 
			logical_size++;                  // logical size increases with each input_num
		}
	}

	num_nums = logical_size;
	return num_arr;
}

void find_num(int *num_arr, int arr_size) {
	int find_num;

	cout << "Enter a number you wish to search: ";
	cin >> find_num;

	cout << find_num << " is present in the array at: ";
	for (int index = 0; index < arr_size; index++) {
		if (find_num == num_arr[index]) {
			cout << (index + 1) << " ";
		}
	}
}
vector<int> make_num_arr2() { // returns integer vector 
	vector<int> numbers;
	int input_num;
	bool am_exiting;

	cout << "Enter numbers into an array -1 to exit: ";

	am_exiting = false;
	while (am_exiting == false) {
		cin >> input_num;
		if (input_num == -1) {
			am_exiting = true;
		}
		else {
			numbers.push_back(input_num);
		}
	}
	return numbers;
}