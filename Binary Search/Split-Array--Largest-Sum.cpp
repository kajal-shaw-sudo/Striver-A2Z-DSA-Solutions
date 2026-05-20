// problem link: https://leetcode.com/problems/split-array-largest-sum/description/

/*
problem: Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/

// brute: linear search: check every candidate answer from max(nums) to sum(nums) linearly. For each candidate sum, greedily count the minimum subarrays needed. Return the first sum where subarrays needed ≤ k.
class Solution {
private:
    int countPartitions(vector<int>& nums, int maxSum) {
        int partitions = 1;
        long long subarraySum = 0;

        for (int num : nums) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }

        return partitions;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        for (int maxSum=maxi; maxSum<=sum; maxSum++) {
            if (countPartitions(nums, maxSum) <= k) {
                return maxSum;
            }
        }

        return maxi;
    }
};
// tc: O(N * S) [where S is the sum of nums], sc: O(1)

// optimal: binary search: binary search on the answer space [max(nums), sum(nums)]. For each mid, greedily check if nums can be split into ≤ k subarrays. Shrink right when valid (look for smaller), expand left otherwise.
class Solution {
private:
    int countPartitions(vector<int>& nums, int maxSum) {
        int partitions = 1;
        long long subarraySum = 0;

        for (int num : nums) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }

        return partitions;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int low = maxi, high = sum;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countPartitions(nums, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
// tc: O(N * log(S)) [where S is the sum of nums], sc: O(1)