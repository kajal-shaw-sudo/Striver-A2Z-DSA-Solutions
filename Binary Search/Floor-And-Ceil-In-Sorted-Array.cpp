/*
problem: Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.

Example 1

Input : nums =[3, 4, 4, 7, 8, 10], x= 5
Output: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2

Input : nums =[3, 4, 4, 7, 8, 10], x= 8
Output: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

// brute: linear scan for the floor and ceil
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();

        int floor = -1, ceil = -1;

        for (int i=0; i<n; i++) {
            if (nums[i] >= x) {
                ceil = nums[i];
                break;
            }
        }

        for (int i=n-1; i>=0; i--) {
            if (nums[i] <= x) {
                floor = nums[i];
                break;
            }
        }

        return {floor, ceil};
    }
};
// tc: O(2*n) = O(n), sc: O(1)

// optimal: binary search for the floor and ceil
class Solution {
private:
    int getFloor(vector<int>& nums, int x) {
        int floor = -1;

        int low = 0, high = nums.size()-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] <= x) {
                floor = nums[mid];
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return floor;
    }

    int getCeil(vector<int>& nums, int x) {
        int ceil = -1;

        int low = 0, high = nums.size()-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] >= x) {
                ceil = nums[mid];
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return ceil;
    }

public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor = getFloor(nums, x);
        int ceil = getCeil(nums, x);

        return {floor, ceil};
    }
};
// tc: O(logn), sc: O(1)