#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /*
       Checks whether the current meeting can be added
       without overlapping with already selected meetings.
    */
    bool canTake(pair<int, int> current, vector<pair<int, int>>& selected) {
        for (auto meeting : selected) {
            /*
               If neither meeting ends strictly before the other starts,
               both meetings overlap and cannot use the same room.
            */
            if (!(current.second < meeting.first ||
                  meeting.second < current.first)) {
                return false;
            }
        }

        return true;
    }

    /*
       Recursively tries all subsets and returns the maximum
       number of non-overlapping meetings.
    */
    int solve(int index, vector<pair<int, int>>& meetings,
              vector<pair<int, int>>& selected) {
        /*
           When all meetings are processed, the current subset
           is complete and no more meetings can be added.
        */
        if (index == meetings.size()) {
            return 0;
        }

        /*
           This choice skips the current meeting because the
           best answer may come from meetings after it.
        */
        int skip = solve(index + 1, meetings, selected);

        int take = 0;

        /*
           The current meeting is taken only if it does not
           overlap with any meeting already selected.
        */
        if (canTake(meetings[index], selected)) {
            selected.push_back(meetings[index]);
            take = 1 + solve(index + 1, meetings, selected);
            selected.pop_back();
        }

        return max(take, skip);
    }

public:
    /*
       Finds the maximum number of meetings by trying every
       possible subset recursively.
    */
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> meetings;

        for (int i = 0; i < start.size(); i++) {
            meetings.push_back({start[i], end[i]});
        }

        vector<pair<int, int>> selected;

        return solve(0, meetings, selected);
    }
};

int main() {
    // Driver code starts
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    Solution sol;
    cout << sol.maxMeetings(start, end);

    return 0;
}