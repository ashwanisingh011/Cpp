#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to generate all unique subsets
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to result
        result.push_back(current);

        // Iterate over the array from 'start' index
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates: if current number is same as previous and not at the start index
            if (i > start && nums[i] == nums[i - 1]) continue;

            // Include nums[i] in current subset
            current.push_back(nums[i]);

            // Recurse for next index
            backtrack(i + 1, nums, current, result);

            // Backtrack: remove last added element
            current.pop_back();
        }
    }

    // Main function to get unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;

        // Start backtracking from index 0
        backtrack(0, nums, current, result);

        return result;
    }
};

// Driver code
int main() {
    Solution obj;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    for (auto subset : ans) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;
}
