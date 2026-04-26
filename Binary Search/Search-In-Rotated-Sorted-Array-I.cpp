// problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

/*
problem: There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

// brute: linear search to find target
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i=0; i<n; i++) {
            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};
// tc: O(n), sc: O(1)

// optimal: modified binary search to find target
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] == target) {
                return mid;
            }

            // if the array contains duplicates (not required in this question)
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // if the target lies int left half, search here
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } 

                else {
                    low = mid + 1;
                }
            } 

            // check if the right half is sorted
            else {
                // if the target lies in the right half, search here
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                }

                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
// tc: O(log n), sc: O(1)
