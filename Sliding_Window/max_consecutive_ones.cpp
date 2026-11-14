#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Finds the longest window containing at most k zeroes.
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLength = 0;

        // Expand the right boundary across the complete array.
        for (int right = 0; right < nums.size(); right++) {

            // Count a zero when it enters the active window.
            if (nums[right] == 0) {
                zeroCount++;
            }

            // Shrink until the window requires at most k flips.
            while (zeroCount > k) {

                // Remove a zero from the count when it leaves the window.
                if (nums[left] == 0) {
                    zeroCount--;
                }

                left++;
            }

            maxLength = max(
                maxLength,
                right - left + 1
            );
        }

        return maxLength;
    }
};

int main() {
    vector<int> nums = {
        1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
    };
    int k = 2;

    Solution solution;

    cout << solution.longestOnes(nums, k) << endl;

    return 0;
}