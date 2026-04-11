// problem: https://leetcode.com/problems/merge-intervals/description/

// brute
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        bool merged = true;

        while (merged) {
            merged = false;
            vector<vector<int>> ans; // reset each pass
            vector<bool> visited(n, false); // reset each pass

            for (int i=0; i<n; i++) {
                if (visited[i]) {
                    continue;
                }

                int start = intervals[i][0];
                int end = intervals[i][1];

                for (int j=i+1; j<n; j++) {
                    if (!visited[j] && intervals[j][0] <= end && intervals[j][1] >= start) {
                        start = min(start, intervals[j][0]);
                        end = max(end, intervals[j][1]);
                        visited[j] = true;
                        merged = true;
                    }
                }

                ans.push_back({start, end});
            }

            intervals = ans; // update for next pass
            n = intervals.size(); // update n for next pass
        }

        return intervals;
    }
};
// tc: O(n^2), sc: O(n)

// optimal 1
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (int i=0; i<n; ) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i + 1;

            while (j < n && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                j++;
            }

            merged.push_back({start, end});

            i = j;
        }

        return merged;
    }
};
// tc: O(nlogn), sc: O(n)

// optimal 2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        for (auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }

            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};
// tc: O(nlogn), sc: O(n)