// problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

/*
problem: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3

Input: nums = [], target = 0
Output: [-1,-1]
*/

// brute: linear scan for the first and last occurence
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = -1, last = -1;

        for (int i=0; i<n; i++) {
            if (nums[i] == target) {
                first = i;
                break;
            }
        }

        for (int i=n-1; i>=0; i--) {
            if (nums[i] == target) {
                last = i;
                break;
            }
        }

        return {first, last};
    }
};
// tc: O(2*n) = O(n), sc: O(1)

// optimal 1: binary search - validate after both searches for finding the first and last positions, as they may point to a different element if target doesn't exist
class Solution {
private:
    int findFirst(vector<int>& nums, int target) {
        int first = -1;

        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] >= target) {
                first = mid;
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int last = -1;

        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] <= target) {
                last = mid;
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return last;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);

        // first and last may point to a different element if target doesn't exist
        if (first == -1 || nums[first] != target) {
            return {-1, -1};
        }

        return {first, last};
    }
};
// tc: O(2*log n) = O(log n), sc: O(1)

// optimal 2: binary search - validate after each search for finding the first and last positions, as they may point to a different element if target doesn't exist
class Solution {
private:
    int findFirst(vector<int>& nums, int target) {
        int first = -1;

        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }

            else if (nums[mid] < target) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int last = -1;

        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }

            else if (nums[mid] > target) {
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return last;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);

        return {first, last};
    }
};
// tc: O(2*log n) = O(log n), sc: O(1)
