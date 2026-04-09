// problem: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// brute (2-pass)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos, neg;

        for (int i=0; i<n; i++) {
            if (nums[i] >= 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        for (int i=0; i<n/2; i++) {
            nums[i*2] = pos[i];
            nums[i*2+1] = neg[i];
        }

        return nums;
    }
};
// tc: O(n), sc: O(n)

// optimal (single-pass)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int pos = 0, neg = 1;

        for (int i=0; i<n; i++) {
            if (nums[i] >= 0) {
                ans[pos] = nums[i];
                pos += 2;
            } else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};
// tc: O(n), sc: O(n)