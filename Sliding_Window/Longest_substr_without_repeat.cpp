#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Uses last-seen positions
    // to move the left boundary directly.
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLen = 0;

        // Move right across the string.
        for (int right = 0; right < s.size(); right++) {

            // Move left only when the
            // duplicate is inside the window.
            if (
                lastSeen.count(s[right]) &&
                lastSeen[s[right]] >= left
            ) {
                left = lastSeen[s[right]] + 1;
            }

            lastSeen[s[right]] = right;

            maxLen = max(
                maxLen,
                right - left + 1
            );
        }

        return maxLen;
    }
};

int main() {
    string s = "abcabcbb";

    Solution solution;

    cout << solution.lengthOfLongestSubstring(s)
         << endl;

    return 0;
}