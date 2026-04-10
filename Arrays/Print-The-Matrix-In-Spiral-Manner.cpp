// problem: https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;

        while (top <= bottom && left <= right) {
            // left to right
            for (int i=left; i<=right; i++) {
                ans.push_back(matrix[top][i]);
            }

            top++;

            // top to bottom
            for (int i=top; i<=bottom; i++) {
                ans.push_back(matrix[i][right]);
            }

            right--;

            // check if there are rows remaining
            if (top <= bottom) {
                // right to left
                for (int i=right; i>=left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }

                bottom--;
            }

            // check if there are cols remaining
            if (left <= right) {
                // bottom to top
                for (int i=bottom; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                }

                left++;
            }
        }

        return ans;
    }
};
// tc: O(m*n), sc: O(1) (not counting the space used to store the answer)