// problem: https://leetcode.com/problems/single-number/description/

// brute (for-loops)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        for (int i=0; i<n; i++) {
            bool flag = true;

            for (int j=0; j<n; j++) {
                if (i != j && nums[i] == nums[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                return nums[i];
            }
        }

        return -1;
    }
};
// tc: O(n^2), sc: O(1)

// better (hashing)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return -1;
    }
};
// tc: O(n), sc: O(n)

// optimal (XOR)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;

        for (int i=0; i<n; i++) {
            xorr ^= nums[i];
        }

        return xorr;
    }
};
// tc: O(n), sc: O(1)