// problem: https://leetcode.com/problems/rotate-array/description/

// brute (for-loop)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        if (n == 0 || k == 0) {
            return;
        }

        vector<int> temp(k);

        for (int i=n-k; i<n; i++) {
            temp[i-n+k] = nums[i];
        }

        for (int i=n-k-1; i>=0; i--) {
            nums[i+k] = nums[i];
        }

        for (int i=0; i<k; i++) {
            nums[i] = temp[i];
        }
    }
};
// tc: O(n), sc: O(k)

// optimal (reverse)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        if (n == 0 || k == 0) {
            return;
        }

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// tc: O(3*n) = O(n), sc: O(1)