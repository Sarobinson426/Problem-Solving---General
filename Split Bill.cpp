#include <iostream>
#include <vector>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b) {
	int ann_bill_total, bob_bill_total, allergy, split_bill;

	ann_bill_total = 0;
	bob_bill_total = 0;
	allergy = 0;
	split_bill = 0;
	for (int x = 0; x < bill.size(); x++) {
		if (x != k) {
			ann_bill_total += bill[x];
		}
		if (x == k) {
			allergy = bill[x];
		}
		else {
			bob_bill_total += bill[x];
		}
		split_bill += bill[x];
	}

	split_bill /= 2;
	ann_bill_total /= 2;
	bob_bill_total = (bob_bill_total / 2) + allergy;

	if (ann_bill_total == b) {
		cout << "Bon Appetit";
	}
	else {
		cout << split_bill - ann_bill_total;
	}
	//cout << ann_bill_total << endl;
	//cout << bob_bill_total << endl;

}

int main()
{
	vector<int> bill = { 3, 10, 2, 9 };
	int anne = 1;
	int b = 7;

	bonAppetit(bill, anne, b);


	return 0;
}