// problem: https://leetcode.com/problems/majority-element/description/

// brute (count frequency of each element) (2-pass)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<n; i++) {
            int count = 0;

            for (int j=0; j<n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            if (count > (n/2)) {
                return nums[i];
            }
        }

        return -1;
    }
};
// tc: O(n^2), sc: O(1)

// better (hashmap)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& it : freq) {
            if (it.second > (n/2)) {
                return it.first;
            }
        }

        return -1;
    }
};
// tc: O(n), sc: O(n)

// optimal (Boyer-Moore Majority Vote Algorithm)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int element, count = 0;

        for (int i=0; i<n; i++) {
            if (count == 0) {
                count = 1;
                element = nums[i];
            }

            else if (nums[i] == element) {
                count++;
            }

            else {
                count--;
            }
        }

        return element;

        /*
        //Since the problem guarantees a majority element exists, 
        //the verification pass is unnecessary — whatever candidate 
        //survives is the answer.

        int count1 = 0;

        for (int i=0; i<n; i++) {
            if (nums[i] == element) {
                count1++;
            }
        }

        if (count1 > (n/2)) {
            return element;
        }

        return -1; // omit when majority element is guaranteed to exist

        // tc: O(2*n) = O(n), sc: O(1)
        */
    }
};
// tc: O(n), sc: O(1)