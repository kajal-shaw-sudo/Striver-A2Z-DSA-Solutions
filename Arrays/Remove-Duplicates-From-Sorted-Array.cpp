// problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

// brute (set) 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());

        int i = 0;
        for (int x : st) {
            nums[i++] = x;
        }

        return st.size();
    }
};
// tc: O(n log n), sc: O(n)

// optimal (2-pointers)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        for (int j=1; j<n; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
// tc: O(n), sc: O(1)