// problem: https://leetcode.com/problems/max-consecutive-ones-iii/description/

// brute
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = 0;

        for (int i=0; i<n; i++) {
            int zeros = 0;

            for (int j=i; j<n; j++) {
                if (nums[j] == 0) {
                    zeros++;
                }

                if (zeros > k) {
                    break;
                }

                maxi = max(maxi, j-i+1);
            }
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(1)

// optimal: using sliding window
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = 0, l = 0, r = 0, zeros = 0;

        while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }

            if (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }

                l++;
            }

            maxi = max(maxi, r-l+1);

            r++;
        }

        return maxi;
    }
};
// tc: O(n), sc: O(1)