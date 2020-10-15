#include <iostream>
#include <vector>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int max_spend_limit, current_max;

    max_spend_limit = 0;
    current_max = 0;
    for (int x = 0; x < keyboards.size(); x++) {
        int key_price = keyboards[x];

        for (int y = 0; y < drives.size(); y++) {
            current_max = keyboards[x] + drives[y];
            if (current_max <= b) {
                if (current_max >= max_spend_limit) {
                    max_spend_limit = keyboards[x] + drives[y];
                }
            }
        }
    }
    if (max_spend_limit > 0 && max_spend_limit < b) {
        return max_spend_limit;
    }
    else {
        return -1;
    }
}

int main()
{
    vector<int> keyboards = { 10, 10 }, drives = { 5, 2, 8 };
    int money_on_hand, result;

    money_on_hand = 10;
    result = getMoneySpent(keyboards, drives, money_on_hand);

    cout << result << endl;

    return 0;
}