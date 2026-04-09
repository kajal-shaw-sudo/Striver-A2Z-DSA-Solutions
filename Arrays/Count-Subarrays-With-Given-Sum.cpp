// problem: https://leetcode.com/problems/subarray-sum-equals-k/description/

// brute (for-loops)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 0;

        for (int i=0; i<n; i++) {
            int sum = 0;

            for (int j=i; j<n; j++) {
                sum += nums[j];

                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
// tc: O(n^2), sc: O(1)

// optimal (hashing)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> prefixSumFreq;

        int prefixSum = 0, count = 0;

        prefixSumFreq[0] = 1;  // occured once

        for (int i=0; i<n; i++) {
            prefixSum += nums[i];

            int remove = prefixSum - k;

            if (prefixSumFreq.find(remove) != prefixSumFreq.end()) {
                count += prefixSumFreq[remove];
            }

            prefixSumFreq[prefixSum]++;
        }

        return count;
    }
};
// tc: O(n), sc: O(n)