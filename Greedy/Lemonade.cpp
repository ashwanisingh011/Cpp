#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Checks whether correct change can be given
     * to every customer in the given order.
     */
    bool lemonadeChange(vector<int>& bills) {
        // Stores how many $5 bills are currently available.
        int five = 0;

        // Stores how many $10 bills are currently available.
        int ten = 0;

        for (int bill : bills) {
            // A $5 bill needs no change and becomes useful later.
            if (bill == 5) {
                five++;
            }
            // A $10 bill needs one $5 bill as change.
            else if (bill == 10) {
                // Without a $5 bill, correct change cannot be given.
                if (five == 0) {
                    return false;
                }

                five--;
                ten++;
            }
            // A $20 bill needs $15 as change.
            else {
                /*
                 * Prefer giving one $10 and one $5
                 * so more $5 bills are saved for later.
                 */
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                /*
                 * If no $10 bill is available, three $5 bills
                 * can still make the required $15 change.
                 */
                else if (five >= 3) {
                    five -= 3;
                }
                // No valid way exists to give $15 change.
                else {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    // Driver code starts
    vector<int> bills = {5, 5, 5, 10, 20};

    Solution solution;
    cout << boolalpha << solution.lemonadeChange(bills) << endl;

    return 0;
}