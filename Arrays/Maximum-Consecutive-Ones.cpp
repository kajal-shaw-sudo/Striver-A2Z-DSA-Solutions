// problem: https://leetcode.com/problems/max-consecutive-ones/description/

// brute
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int count = 0, maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                count = 0;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};
// tc: O(n), sc: O(1)