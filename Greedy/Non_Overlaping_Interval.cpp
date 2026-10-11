#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Orders intervals by smaller end time first.
    static bool comp(vector<int>& first, vector<int>& second) {
        return first[1] < second[1];
    }

    // Returns the minimum number of intervals to remove.
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Empty input has no overlapping interval to remove.
        if (intervals.empty()) {
            return 0;
        }

        // Sort intervals so the interval ending earliest is considered first.
        sort(intervals.begin(), intervals.end(), comp);

        int removeCount = 0;
        int lastEndTime = intervals[0][1];

        // Check every remaining interval against the last kept interval.
        for (int i = 1; i < intervals.size(); i++) {
            // A start before the last kept end time means the current interval overlaps.
            if (intervals[i][0] < lastEndTime) {
                removeCount++;
            // A start at or after the last kept end time means the interval can stay.
            } else {
                lastEndTime = intervals[i][1];
            }
        }

        return removeCount;
    }
};

// Driver code
int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}, {2, 4}, {4, 5}};

    // instance for class Solution
    Solution sol;

    cout << sol.eraseOverlapIntervals(intervals) << '\n';
    return 0;
}