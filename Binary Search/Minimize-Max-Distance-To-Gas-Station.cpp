/*
problem: Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.
The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.
Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.
Find the minimum value of dist.
Your answer will be accepted if it is within 1e-6 of the true value.

Example 1
Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 10
Output: 0.50000
Explanation:
One of the possible ways to place 10 gas stations is [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10].
Thus the maximum difference between adjacent gas stations is 0.5.
Hence, the value of dist is 0.5.
It can be shown that there is no possible way to add 10 gas stations in such a way that the value of dist is lower than this.

Example 2
Input : n = 10, arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 1
Output: 1.00000
Explanation:
One of the possible ways to place 1 gas station is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
New Gas Station is at 11.
Thus the maximum difference between adjacent gas stations is still 1.
Hence, the value of dist is 1.
It can be shown that there is no possible way to add 1 gas station in such a way that the value of dist is lower than this. 
*/

// brute: greedy placement - for each of the k new stations, scan all gaps and place the station in whichever gap currently has the largest section length. Repeat k times, then return the maximum section length across all gaps.
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();

       vector<int> howMany(n-1, 0);

       for (int gas=0; gas<k; gas++) {
        long double maxSection = -1;
        int maxIndex = -1;

        for (int i=0; i<n-1; i++) {
            long double sectionLength = (long double)(arr[i+1] - arr[i]) / (howMany[i] + 1);

            if (maxSection < sectionLength) {
                maxSection = sectionLength;
                maxIndex = i;
            }
        }

        howMany[maxIndex]++;
       }

       long double ans = -1;
       for (int i=0; i<n-1; i++) {
        ans = max(ans, (long double)(arr[i+1] - arr[i]) / (howMany[i] + 1));
       }

       return ans;
    }
};
// tc: O(n * k), sc: O(n)

// better: max heap - same greedy strategy as brute, but use a max-heap to avoid scanning all gaps each time — always pop the largest section, increment its count, and push back its updated section length. Repeat k times; the heap top is the answer.
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();

       vector<int> howMany(n-1, 0);

       priority_queue<pair<long double, int>> pq;

       for (int i=0; i<n-1; i++) {
        pq.push({(long double)(arr[i+1] - arr[i]), i});
       }

       for (int gas=0; gas<k; gas++) {
        auto [maxSection, index] = pq.top(); pq.pop();

        howMany[index]++;

        long double newSection = (long double)(arr[index+1] - arr[index]) / (howMany[index] + 1);

        pq.push({newSection, index});
       }

       return pq.top().first;
    }
};
// tc: O(n log n + k log n), sc: O(n)

// optimal: binary search - binary search on the answer space [0, max_gap]. For a given candidate distance mid, count the minimum stations needed — each gap of length L requires floor(L / mid) inserted stations. If total stations needed ≤ k, mid is achievable so shrink right; otherwise expand left. Iterate until precision within 1e-6.
class Solution {
private: 
    int countStations(vector<int>& arr, long double distance) {
        int n = arr.size();

        int count = 0;

        for (int i=0; i<n-1; i++) {
            count += (int)((long double)(arr[i+1] - arr[i]) / distance);
        }

        return count;
    }

public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();

       long double low = 0, high = 0;

       for (int i=0; i<n-1; i++) {
        high = max(high, (long double)(arr[i+1] - arr[i]));
       }

       while (high - low > 1e-6) {
            long double mid = low + (high - low) / 2;

            if (countStations(arr, mid) <= k) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }
};
// tc: O(n * log(max(max_gap) / 10^6)) [where, max_gap = max(arr[i+1] - arr[i])], sc: O(1)
