#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Counts subarrays whose sum is exactly equal to goal.
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        // No non-empty subarray can be formed.
        if (n == 0) {
            return 0;
        }

        int count = 0;

        // Choose every possible starting index.
        for (int start = 0; start < n; start++) {

            // Choose every possible ending index for the current start.
            for (int end = start; end < n; end++) {
                int currentSum = 0;

                // Calculate the sum of the selected subarray from scratch.
                for (int i = start; i <= end; i++) {
                    currentSum += nums[i];
                }

                // Count the subarray when its sum matches the goal.
                if (currentSum == goal) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    Solution solution;

    cout << solution.numSubarraysWithSum(nums, goal)
         << endl;

    return 0;
}