/*
problem: Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.

Example 1

Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 4
Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

Example 2

Input: nums = [3, 4, 5, 1, 2]
Output: 3
Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.
*/

// brute: linear search for the minimum element and return its index
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();

        int mini = 1e9, minIndex = -1;

        for (int i=0; i<n; i++) {
            if (mini > nums[i]) {
                mini = nums[i];
                minIndex = i;
            }
        }

        return minIndex;
    }
};
// tc: O(n), sc: O(1)


// optimal: modified binary search to find the minimum element and return its index
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
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

        return low;
    }
};
// tc: O(log n), sc: O(1)