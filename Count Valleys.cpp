#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int countingValleys(int steps, string path) {
	int valley_count, current_step, step_count;
	bool is_ascending;

	valley_count = 0;
	step_count = 0;
	is_ascending = false;
	for (int x = 0; x < path.length(); x++) {
		current_step = static_cast<int>(path[x]);

		if (current_step == 85) {
			is_ascending = true;
			step_count++;
		}
		else if (current_step == 68) {
			is_ascending = false;
			step_count--;
		}

		if (is_ascending == true && step_count == 0) {
			valley_count++;
		}
	}

	return valley_count;
}

int main()
{
	string steps;
	int result;
	steps = "UDDDUDUU";

	result = countingValleys(steps.length(), steps);
	cout << result << endl;

	return 0;
}

