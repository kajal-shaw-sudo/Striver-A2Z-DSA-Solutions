// problem link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

/*
problem: You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

// brute: hashmap to count the frequency of each element and return the element with frequency 1
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

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

// better 1: linear search for the single element
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // check first and last elements separately (no left/right neighbors on both sides)
        if (nums[0] != nums[1]) {
            return nums[0];
        }

        if (nums[n-1] != nums[n-2]) {
            return nums[n-1];
        }

        // check the middle elements
        for (int i=1; i<n-1; i++) {
            if (nums[i-1] != nums[i] && nums[i] != nums[i+1]) {
                return nums[i];
            }
        }

        return -1;
    }
};
// tc: O(n), sc: O(1)

// better 2: XOR
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;

        for (int i=0; i<n; i++) {
            xorr ^= nums[i];
        }

        return xorr;
    }
};
// tc: O(n), sc: O(1)

// optimal: modified binary search to find the single element
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (nums[0] != nums[1]) {
            return nums[0];
        }

        if (nums[n-1] != nums[n-2]) {
            return nums[n-1];
        }

        int low = 1, high = n-2;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }

            // ensure is mid is at even index
            if (mid % 2 == 1) {
                mid--;
            }

            // pairs should start at even indices and ends at odd indices (e.g., i=0 and i=1)
            // if single element is encountered, this pattern will break and all pairs then start at odd indices, binary search exploits this pattern
            if (nums[mid] == nums[mid+1]) {
                low = mid + 2;
            }

            else {
                high = mid - 1;
            }
        }

        return nums[low];
    }
};
// tc: O(log n), sc: O(1)
