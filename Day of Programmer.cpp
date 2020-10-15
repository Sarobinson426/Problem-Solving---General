#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
using namespace std;

string dayOfProgrammer(int year) {
	string year_convert;

	if (year < 1700) {
		return 0;
	}
	else if (year >= 1700 && year <= 1917) {
		if ((year % 4) == 0) {
			year_convert = to_string(year);
			return "12.09." + year_convert;
		}
		else {
			year_convert = to_string(year);
			return "13.09." + year_convert;
		}
	}
	else if (year == 1918) {
		return "26.09.1918";
	}
	else if (year >= 1919 && year <= 2700) {
		if (((year % 400) == 0) || ((year % 4) == 0 && (year % 100) != 0)) {
			year_convert = to_string(year);
			return "12.09." + year_convert;
		}
		else {
			year_convert = to_string(year);
			return "13.09." + year_convert;
		}
	}
	else {
		year_convert = to_string(year);
		return "12.09." + year_convert;
	}
}

int main()
{
	int year;
	string result;

	cout << "Put in the year (int): " << endl;
	cin >> year;

	result = dayOfProgrammer(year);
	cout << result << endl;

	return 0;
}