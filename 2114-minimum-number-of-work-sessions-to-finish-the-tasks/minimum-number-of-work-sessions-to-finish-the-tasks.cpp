class Solution {
public:
    bool canDistribute(vector<int>& tasks, vector<int>& sessions, int sessionTime, int index) {
        if (index == tasks.size()) return true;

        for (int i = 0; i < sessions.size(); i++) {
            if (sessions[i] + tasks[index] <= sessionTime) {
                sessions[i] += tasks[index];
                if (canDistribute(tasks, sessions, sessionTime, index + 1)) {
                    return true;
                }
                sessions[i] -= tasks[index];
            }

            if (sessions[i] == 0) break;
        }
        return false;
    }

    bool findst(vector<int>& tasks, int mid, int sessionTime) {
        vector<int> sessions(mid, 0);
        return canDistribute(tasks, sessions, sessionTime, 0);
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size();
        int l = 1, h = n, ans = n;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (findst(tasks, mid, sessionTime)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};