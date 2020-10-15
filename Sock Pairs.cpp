#include <iostream>
#include <vector>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
	int key, pair_count, all_pairs;

	pair_count = 0;
	all_pairs = 0;
	for (int x = 0; x < ar.size(); x++) {
		key = ar[x];
		if (key != 0) {
			for (int y = 0; y < ar.size(); y++) {
				if (key == ar[y]) {
					pair_count++;
					ar[y] = 0;
					if (pair_count == 2) {
						all_pairs++;
						pair_count = 0;
					}
				}
			}
			pair_count = 0;
		}
	}


	return all_pairs;
}

int main()
{
	vector<int> v = { 10, 20, 20, 10, 10, 30, 50, 10, 20 };
	int result;

	result = sockMerchant(v.size(), v);

	cout << result;

	return 0;
}