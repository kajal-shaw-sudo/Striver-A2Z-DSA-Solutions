// problem: https://leetcode.com/problems/binary-subarrays-with-sum/description/

// brute
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int count = 0;

        for (int i=0; i<n; i++) {
            int sum = 0;

            for (int j=i; j<n; j++) {
                sum += nums[j];

                if (sum == goal) {
                    count++;
                }
            }
        }

        return count;
    }
};
// tc: O(n^2), sc: O(1)

// optimal: using prefix sum and hashing
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int count = 0, sum = 0;

        unordered_map<int, int> prefixSumCount;

        prefixSumCount[0] = 1;

        for (int i=0; i<n; i++) {
            sum += nums[i];

            if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[sum-goal];
            }

            prefixSumCount[sum]++;
        }

        return count;
    }
};
// tc: O(n), sc: O(n)