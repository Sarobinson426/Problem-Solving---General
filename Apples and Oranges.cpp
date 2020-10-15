#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
	int distance, fruit_bowl, fruit_salad;

	fruit_bowl = 0;
	for (vector<int>::iterator it_a = apples.begin(); it_a != apples.end(); it_a++) {
		distance = (a + *it_a);
		if (distance >= s && distance <= t) {
			fruit_bowl++;
		}
	}

	fruit_salad = 0;
	for (vector<int>::iterator it_o = oranges.begin(); it_o != oranges.end(); it_o++) {
		distance = (b + *it_o);
		if (distance >= s && distance <= t) {
			fruit_salad++;
		}
	}

	cout << fruit_bowl << endl;
	cout << fruit_salad << endl;
}

int main()
{
	vector<int> apples = { -2, 0, 1 }, oranges = { 5, -6 };

	countApplesAndOranges(7, 11, 5, 15, apples, oranges);

	return 0;
}

