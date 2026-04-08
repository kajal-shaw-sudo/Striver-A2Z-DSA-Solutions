// problem: https://leetcode.com/problems/move-zeroes/description/

// brute
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return;
        }

        vector<int> temp(n, 0);

        int index = 0;

        for (int i=0; i<n; i++) {
            if (nums[i] != 0) {
                temp[index++] = nums[i];
            }
        }

        for (int i=0; i<n; i++) {
            nums[i] = temp[i];
        }
    }
};
// tc: O(n), sc: O(n)

// optimal (2-pointers)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return;
        }

        int j = -1;

        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        if (j == -1) {
            return;
        }

        for (int i=j+1; i<n; i++) {
            if (nums[i] != 0) {
                swap(nums[j], nums[i]);
                j++;
            }
        }
    }
};
// tc: O(n), sc: O(1)