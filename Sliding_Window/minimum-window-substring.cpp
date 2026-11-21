#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Checks whether the current window contains all required characters.
    bool isValid(
        const vector<int>& need,
        const vector<int>& window
    ) {
        // Compare every ASCII character with its required frequency.
        for (int i = 0; i < 128; i++) {
            // The window is invalid if any required count is missing.
            if (window[i] < need[i]) {
                return false;
            }
        }

        return true;
    }

public:
    // Finds the minimum valid window by checking every substring.
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        // A valid window cannot exist in these cases.
        if (n == 0 || m == 0 || n < m) {
            return "";
        }

        vector<int> need(128, 0);

        // Store the required frequency of every character in t.
        for (char ch : t) {
            need[(unsigned char)ch]++;
        }

        int minLength = INT_MAX;
        string answer = "";

        // Choose every possible starting index.
        for (int start = 0; start < n; start++) {

            // Choose every possible ending index for this start.
            for (int end = start; end < n; end++) {
                vector<int> window(128, 0);

                // Rebuild frequencies for the selected substring.
                for (int i = start; i <= end; i++) {
                    window[(unsigned char)s[i]]++;
                }

                // The first valid window is shortest for this start.
                if (isValid(need, window)) {
                    int currentLength = end - start + 1;

                    // Keep the smallest valid window found so far.
                    if (currentLength < minLength) {
                        minLength = currentLength;
                        answer = s.substr(start, currentLength);
                    }

                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution solution;

    cout << solution.minWindow(s, t) << endl;

    return 0;
}