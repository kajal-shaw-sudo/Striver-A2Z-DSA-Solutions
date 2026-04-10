// problem: https://leetcode.com/problems/maximum-subarray/description/

// brute (generate all subarrays) (3-pass)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                int sum = 0;

                for (int k=i; k<=j; k++) {
                    sum += nums[k];

                    maxi = max(maxi, sum);
                }
            }
        }

        return maxi;
    }
};
// tc: O(n^3), sc: O(1)

// slightly better (generate all subarrays) (2-pass)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            int sum = 0;

            for (int j=i; j<n; j++) {
                sum += nums[j];

                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(1)

// better (prefix sum)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int prefixSum = 0, minPrefix = 0, maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            prefixSum += nums[i];
            // prefixSum - minPrefix = prefixSum[j] - prefixSum[i-1] (for sum of subarray [i...j])
            maxi = max(maxi, prefixSum - minPrefix);
            minPrefix = min(minPrefix, prefixSum);
        }
        return maxi;
    }
};
// tc: O(n), sc: O(1)

// optimal (Kadane's Algorithm) (standard approach)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN, sum = 0;

        for (int i=0; i<n; i++) {
            sum += nums[i];

            maxi = max(maxi, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};
// tc: O(n), sc: O(1)