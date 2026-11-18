#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Counts distinct characters
    // inside the selected range.
    int countDistinct(
        const string& s,
        int start,
        int end
    ) {
        unordered_set<char> distinct;

        // Scan the selected substring.
        for (int i = start; i <= end; i++) {
            distinct.insert(s[i]);
        }

        return distinct.size();
    }

public:
    // Finds the longest substring
    // with at most k distinct characters.
    int longestSubstringAtMostKDistinct(
        string s,
        int k
    ) {
        int n = s.size();

        // No valid non-empty substring
        // can exist in these cases.
        if (n == 0 || k <= 0) {
            return 0;
        }

        int maxLength = 0;

        // Try every possible start.
        for (int start = 0; start < n; start++) {

            // Extend the substring
            // from the current start.
            for (int end = start; end < n; end++) {
                int distinctCount =
                    countDistinct(s, start, end);

                // Further expansion cannot
                // reduce the distinct count.
                if (distinctCount > k) {
                    break;
                }

                maxLength = max(
                    maxLength,
                    end - start + 1
                );
            }
        }

        return maxLength;
    }
};

int main() {
    string s = "eceba";
    int k = 2;

    Solution solution;

    cout << solution.longestSubstringAtMostKDistinct(
        s,
        k
    ) << endl;

    return 0;
}