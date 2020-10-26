//Author: Shaun Robinson
//Program: Power
//Description: Takes and integer and multiplys it by itself a
//number of time specified by user

#include<iostream>
using namespace std;

int exponent(int base, int power) {
	if (power == 0) {
		return 1;
	}
	else {
		int halfpow = exponent(base, power / 2); // tail recursion stacks 'power / 2' until pow = 0
		int fullpow = halfpow * halfpow;         // pow = 12, 6, 3, 1 then calulations start
		if (power % 2 == 1) {                    // half pow will first be 1 then 9 then 27 then 729
			fullpow *= base;
		}
		return fullpow;
	}
}

int main() {
	int base, power, result;

	base = 3;
	power = 12;
	result = exponent(base, power);

	cout << base << " to the power of " << power << " is: " << result << endl;
	cout << "Hello?" << endl;
	
	return 0;
}