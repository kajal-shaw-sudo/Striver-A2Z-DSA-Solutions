// problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

/*
problem: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.

Example 1

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
*/

// brute: linear search for the minimum element
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int mini = 1e9;

        for (int i=0; i<n; i++) {
            mini = min(mini, nums[i]);
        }

        return mini;
    }
};
// tc: O(n), sc: O(1)

// optimal: modified binary search to find the minimum element
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n-1;

        while (low < high) {
            int mid = low + (high-low)/2;

            if (nums[mid] > nums[high]) {
                // minimum lies in right half
                low = mid + 1;
            }

            else {
                // minimum lies in left half (including mid)
                high = mid;
            }
        }

        return nums[low];
    }
};
// tc: O(log n), sc: O(1)

/*
Note: Use while (left < right) with right = mid — it's the natural, clean fit for this problem because we're converging on a point, not searching for an exact match (like in classic binary search where <= is common).
left <= right is great for finding a value. left < right is better for finding a boundary/minimum.
*/