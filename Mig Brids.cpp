#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
using namespace std;

int migratoryBirds(vector<int> arr) {
	vector<int> count(arr.size());
	int max, return_num;

	for (vector<int>::iterator it = count.begin(); it != count.end(); it++) {
		*it = 0;
	}

	for (int x = 0; x < arr.size(); x++) {
		count[arr[x]]++;
	}

	max = count[0];
	return_num = 0;
	for (int x = 1; x <= 5; x++) {
		if (count[x] > max) {
			max = count[x];
			return_num = x;
		}
	}

	return return_num;
}

int main()
{
	vector<int> arr = { 1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4, 4, 2, 2, 2, 2 };
	int result;

	result = migratoryBirds(arr);
	cout << result << endl;

	return 0;
}