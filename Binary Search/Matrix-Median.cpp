/*
problem: Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.

Example 1
Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ] 
Output: 5
Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5
*/

// brute: linear search - flatten the 2D matrix to 1D array -> sort -> return the middle element
class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        vector<int> arr;

        for (auto& row : matrix) {
            for (int val : row) {
                arr.push_back(val);
            }
        }

        sort(arr.begin(), arr.end());

        int n = arr.size();

        return arr[n/2];
    }
};
// tc: O(m*n*log(m*n)), sc: O(m*n)

// optimal: binary search in rows
class Solution{
private:
    int countLessEqual(vector<int>& row, int mid) {
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

public:
    int findMedian(vector<vector<int>>&matrix) {
        int m = matrix.size(), n = matrix[0].size();

        int low = matrix[0][0], high = matrix[0][n-1];

        for (int i=1; i<m; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n-1]);
        }

        int median = (m * n + 1) / 2;

        while (low < high) {
            int mid = low + (high-low)/2;

            int count = 0;

            for (int i=0; i<m; i++) {
                //count elements ≤ mid per row
                count += countLessEqual(matrix[i], mid);
            }

            // if count is less than half, median is greater
            if (count < median) {
                low = mid + 1;
            }

            else {
                high = mid;
            }
        }

        return low;
    }
};
// tc: O((m*log(n)*log(max-min)), sc: O(1)
