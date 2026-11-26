#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Counts valid substrings using a sliding window.
    long long numberOfSubstrings(string s) {
        int n = s.size();

        // At least three characters are required.
        if (n < 3) {
            return 0;
        }

        vector<int> frequency(3, 0);

        int left = 0;
        long long count = 0;

        // Expand the window by moving the right boundary.
        for (int right = 0; right < n; right++) {
            frequency[s[right] - 'a']++;

            // Shrink while the current window contains all three characters.
            while (
                frequency[0] > 0 &&
                frequency[1] > 0 &&
                frequency[2] > 0
            ) {
                // Every later ending gives another valid substring.
                count += n - right;

                frequency[s[left] - 'a']--;
                left++;
            }
        }

        return count;
    }
};

int main() {
    string s = "abcabc";

    Solution solution;

    cout << solution.numberOfSubstrings(s) << endl;

    return 0;
}