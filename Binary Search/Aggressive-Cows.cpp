/*
problem: Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

Example 1
Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]
Output: 3
Explanation:
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.
In no manner can we increase the minimum distance beyond 3.

Example 2
Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]
Output: 5
Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions [1, 6]. 
*/

// brute: sort the array and then check for each possible distance from 1 to max(nums) - min(nums) if we can place k cows with that minimum distance, return the maximum valid distance
class Solution {
private:
    bool canWePlace(vector<int>& stalls, int cows, int dist) {
        int count = 1; // 1 for stall 0 which is already placed
        int lastPosition = stalls[0];

        for (int i=1; i<stalls.size(); i++) {
            if (stalls[i] - lastPosition >= dist) {
                count++;
                lastPosition = stalls[i];
            }

            if (count >= cows) {
                return true;
            }
        }

        return false;
    }

public:
    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int maxDistance = nums[n-1] - nums[0];

        int ans = 0;

        for (int dist=1; dist<=maxDistance; dist++) {
            if (canWePlace(nums, k, dist)) {
                ans = dist;
            }
        }

        return ans;
    }
};
// tc: O(N log N + N * (D) [where D is the maximum distance which is max(nums) - min(nums)], sc: O(1)

// binary search: sort the array and then use binary search on the distance from 1 to max(nums) - min(nums) to find the maximum valid distance
class Solution {
private:
    bool canWePlace(vector<int>& stalls, int cows, int dist) {
        int count = 1; // 1 for stall 0 which is already placed
        int lastPosition = stalls[0];

        for (int i=1; i<stalls.size(); i++) {
            if (stalls[i] - lastPosition >= dist) {
                count++;
                lastPosition = stalls[i];
            }

            if (count >= cows) {
                return true;
            }
        }

        return false;
    }

public:
    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int maxDistance = nums[n-1] - nums[0];

        int ans = 0;

        int low = 1, high = maxDistance;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canWePlace(nums, k, mid)) {
                ans = mid;
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
// tc: O(N log N + N log D [where D is the maximum distance which is max(nums) - min(nums)], sc: O(1)