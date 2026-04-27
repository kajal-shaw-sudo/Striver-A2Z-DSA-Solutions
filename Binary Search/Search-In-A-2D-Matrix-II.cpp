// problem link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

/*
problem: Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example 1

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
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
            if (matrix[i][0] <= target && target <= matrix[i][n-1]) {
                if (binarySearch(matrix[i], target)) {
                    return true;
                }
            }
        }

        return false;
    }
};
// tc: O(m*log(n)), sc: O(1)

// optimal: top right corner traversal approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int row = 0, col = n-1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }

            else if (matrix[row][col] > target) {
                col--;  // move left to find smaller elements
            }

            else {
                row++; // move down to find larger elements
            }
        }

        return false;
    }
};
// tc: O(m+n), sc: O(1)