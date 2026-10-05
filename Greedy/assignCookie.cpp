#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * Finds the maximum number of satisfied children
     * by checking cookies for each child one by one.
     */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // This stores whether a cookie has already been assigned.
        vector<bool> used(s.size(), false);

        // This stores how many children have been satisfied so far.
        int satisfiedChildren = 0;

        for (int childIndex = 0; childIndex < g.size(); childIndex++) {
            for (int cookieIndex = 0; cookieIndex < s.size(); cookieIndex++) {
                // A cookie can be used only if it is unused
                // and large enough for the current child.
                if (!used[cookieIndex] && s[cookieIndex] >= g[childIndex]) {
                    used[cookieIndex] = true;
                    satisfiedChildren++;
                    break;
                }
            }
        }

        return satisfiedChildren;
    }
};

// Driver code starts
int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    Solution sol;
    cout << sol.findContentChildren(g, s) << endl;

    return 0;
}