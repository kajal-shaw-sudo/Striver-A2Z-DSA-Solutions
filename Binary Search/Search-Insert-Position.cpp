// problem link: https://leetcode.com/problems/search-insert-position/description/

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
*/

// brute: linear scan for the first index where nums[index] >= target
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i=0; i<n; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return n;
    }
};
// tc: O(n), sc: O(1)

// optimal: binary search for the first index where nums[index] >= target
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int ans;

        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] >= target) {
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
// tc: O(logn) , sc: O(1)