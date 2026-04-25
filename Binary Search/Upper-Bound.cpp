/*
problem: Given a sorted array of nums and an integer x, write a program to find the upper bound of x.

The upper bound of x is defined as the smallest index i such that nums[i] > x.
If no such index is found, return the size of the array.

Example 1

Input : n= 4, nums = [1,2,2,3], x = 2
Output:3
Explanation: Index 3 is the smallest index such that arr[3] > x.
*/

// brute: linear scan for the first index where nums[index] > x
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();

        for (int i=0; i<n; i++) {
            if (nums[i] > x) {
                return i;
            }
        }

        return -1;
    }
};
// tc: O(n), sc: O(1)

// optimal: binary search for the first index where nums[index] > x
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();

        int ans;

        int left = 0, right = n-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] > x) {
                ans = mid;
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
// tc: O(logn) , sc: O(1)