#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Uses a sliding window
    // with character frequencies.
    int characterReplacement(string s, int k) {
        int n = s.size();

        // No valid substring can exist
        // for these input conditions.
        if (n == 0 || k < 0) {
            return 0;
        }

        vector<int> frequency(26, 0);

        int left = 0;
        int maxFrequency = 0;
        int maxLength = 0;

        // Expand the window with right.
        for (int right = 0; right < n; right++) {
            int index = s[right] - 'A';
            frequency[index]++;

            maxFrequency = max(
                maxFrequency,
                frequency[index]
            );

            int currentLength =
                right - left + 1;

            // Shrink once when the window
            // needs too many replacements.
            if (currentLength - maxFrequency > k) {
                frequency[s[left] - 'A']--;
                left++;
            }

            // Measure the adjusted
            // window after possible shrinking.
            currentLength =
                right - left + 1;

            maxLength = max(
                maxLength,
                currentLength
            );
        }

        return maxLength;
    }
};

int main() {
    string s = "AABABBA";
    int k = 1;

    Solution solution;

    cout << solution.characterReplacement(s, k)
         << endl;

    return 0;
}