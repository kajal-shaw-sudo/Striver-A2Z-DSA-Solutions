// problem: https://leetcode.com/problems/next-permutation/description/

// brute (generate all permutations and find the next one)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> allPermutations;

        vector<int> original = nums;

        sort(nums.begin(), nums.end());

        do {
            allPermutations.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        for (int i=0; i<allPermutations.size(); i++) {
            if (allPermutations[i] == original) {
                if (i == allPermutations.size() - 1) {
                    nums = allPermutations[0];
                    return;
                }

                nums = allPermutations[i+1];
            }
        }
    }
};
// tc: O(n*n!), sc: O(n*n!)

// optimal (find the rightmost pair of indices i and j such that nums[i] < nums[j], then swap the values at those indices, then reverse the subarray starting at index i+1 and ending at the last index)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int index = -1;

        for (int i=n-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i=n-1; i>index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};
// tc: O(n), sc: O(1)