#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns all intervals after merging overlaps with look-ahead scanning.
    vector<vector<int>> mergeBrute(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // A list with at most one interval is already merged.
        if (n <= 1) {
            return intervals;
        }

        // Sort intervals by start time so possible overlaps become adjacent.
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Try to build one merged interval starting from each position.
        for (int i = 0; i < n; i++) {
            // A covered interval is already part of the last merged range.
            if (!result.empty() && intervals[i][1] <= result.back()[1]) {
                continue;
            }

            int start = intervals[i][0];
            int end = intervals[i][1];

            // Look ahead and absorb every interval that overlaps the current range.
            for (int j = i + 1; j < n; j++) {
                // Overlap means the current merged range may need a larger end.
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                // A later start beyond the current end means the merge range is complete.
                } else {
                    break;
                }
            }

            result.push_back({start, end});
        }

        return result;
    }
};

// Driver code
int main() {
    vector<vector<int>> intervals = {{8, 10}, {1, 3}, {2, 6}, {15, 18}, {17, 20}, {10, 12}, {7, 9}};

    // instance for class Solution
    Solution sol;

    vector<vector<int>> result = sol.mergeBrute(intervals);

    // Print every merged interval.
    for (vector<int>& interval : result) {
        cout << '[' << interval[0] << ", " << interval[1] << "] ";
    }
    cout << '\n';
    return 0;
}