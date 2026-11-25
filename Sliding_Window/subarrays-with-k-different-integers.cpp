#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Counts distinct values
    // inside the selected range.
    int countDistinct(
        const vector<int>& nums,
        int start,
        int end
    ) {
        unordered_set<int> distinct;

        // Scan the selected subarray.
        for (int i = start; i <= end; i++) {
            distinct.insert(nums[i]);
        }

        return distinct.size();
    }

public:
    // Counts subarrays containing
    // exactly k distinct integers.
    int subarraysWithKDistinct(
        vector<int>& nums,
        int k
    ) {
        int n = nums.size();

        // No valid non-empty subarray
        // can exist in these cases.
        if (n == 0 || k <= 0) {
            return 0;
        }

        int count = 0;

        // Try every possible start.
        for (int start = 0; start < n; start++) {

            // Try every possible end
            // for the current start.
            for (int end = start; end < n; end++) {
                int distinctCount = countDistinct(
                    nums,
                    start,
                    end
                );

                // Count ranges having
                // exactly k distinct values.
                if (distinctCount == k) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    Solution solution;

    cout << solution.subarraysWithKDistinct(
        nums,
        k
    ) << endl;

    return 0;
}