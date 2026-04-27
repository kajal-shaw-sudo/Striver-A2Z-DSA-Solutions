// problem link: https://leetcode.com/problems/search-a-2d-matrix/description/

/*
problem: You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Example 1

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

// brute: linear search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};
// tc: O(m*n), sc: O(1)

// better: binary search on each row
class Solution {
private:
    bool binarySearch(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] == target) {
                return true;
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i=0; i<m; i++) {
            // check if target can be within this row
            if (matrix[i][0] <= target && target <= matrix[i][n-1]) {
                // apply binary search on this row
                if (binarySearch(matrix[i], target)) {
                    return true;
                }
            }
        }

        return false;
    }
};
// tc: O(m*log(n)), sc: O(1)

// optimal: binary search on the whole matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int low = 0, high = (m*n)-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            }

            else if (matrix[row][col] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return false;
    }
};
// tc: O(log(m*n)), sc: O(1)