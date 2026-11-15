#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Finds the longest valid section by growing from every start.
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;

        // Try every tree as the beginning of a collection.
        for (int start = 0; start < n; start++) {
            unordered_map<int, int> frequency;

            // Expand the section while at most two fruit types remain.
            for (int end = start; end < n; end++) {
                frequency[fruits[end]]++;

                // A third type makes every later extension invalid.
                if (frequency.size() > 2) {
                    break;
                }

                maxFruits = max(
                    maxFruits,
                    end - start + 1
                );
            }
        }

        return maxFruits;
    }
};

int main() {
    vector<int> fruits = {1, 2, 1, 2, 3};

    Solution solution;

    cout << solution.totalFruit(fruits) << endl;

    return 0;
}