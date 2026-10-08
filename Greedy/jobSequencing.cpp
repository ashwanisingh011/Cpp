#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

class Solution {
public:
    // Orders jobs by higher profit first.
    static bool comparison(Job first, Job second) {
        return first.profit > second.profit;
    }

    // Returns the number of jobs done and the maximum profit.
    vector<int> jobScheduling(Job jobs[], int n) {
        // Consider higher-profit jobs before lower-profit jobs.
        sort(jobs, jobs + n, comparison);

        int maxDeadline = 0;

        // Find the largest deadline to size the timeline.
        for (int i = 0; i < n; i++) {
            // A larger deadline increases the required timeline length.
            if (jobs[i].deadline > maxDeadline) {
                maxDeadline = jobs[i].deadline;
            }
        }

        vector<int> timeline(maxDeadline + 1, -1);
        int countJobs = 0;
        int totalProfit = 0;

        // Try to schedule each job in descending profit order.
        for (int i = 0; i < n; i++) {
            // Search for the latest free slot before this job's deadline.
            for (int slot = jobs[i].deadline; slot > 0; slot--) {
                // A free slot allows this job to be scheduled.
                if (timeline[slot] == -1) {
                    timeline[slot] = jobs[i].id;
                    countJobs++;
                    totalProfit += jobs[i].profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};

// Driver code
int main() {
    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // instance for class Solution
    Solution sol;

    vector<int> result = sol.jobScheduling(jobs, n);
    cout << result[0] << ' ' << result[1] << '\n';
    return 0;
}