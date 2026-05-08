// problem link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

/*
problem: Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
The test cases are generated so that there will be an answer.

Example 1:
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).

Example 2:
Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
*/

// brute: linear search from 1 to max(nums), return the smallest divisor such that the sum of division results is <= threshold
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());

        for (int divisor=1; divisor<=maxi; divisor++) {
            long long sum = 0;

            for (int i=0; i<n; i++) {
                sum += ceil((double)nums[i] / divisor);
            }

            if (sum <= threshold) {
                return divisor;
            }
        }

        return -1;
    }
};
// tc: O(max(nums) * n), sc: O(1)

// optimal: using binary search from 1 to max(nums), return the smallest divisor such that the sum of division results is <= threshold
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());

        int ans = -1;

        int low = 1, high = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int sum = 0;

            for (int i=0; i<n; i++) {
                sum += ceil((double)nums[i] / mid);
            }

            if (sum <= threshold) {
                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
// tc: O(n * log(max(nums))), sc: O(1)