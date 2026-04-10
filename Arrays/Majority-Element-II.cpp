// problem: https://leetcode.com/problems/majority-element-ii/description/

// brute (count frequency of each element) (2-pass)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for (int i=0; i<n; i++) {
            int count = 0;

            for (int j=0; j<n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            if ((count > (n/3)) && (find(ans.begin(), ans.end(), nums[i]) == ans.end())) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
// tc: O(n^2), sc: O(1)

// better (hashmap)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> freq;

        vector<int> ans;

        for (int num : nums) {
            freq[num]++;
        }

        for (auto& it : freq) {
            if (it.second > (n/3)) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
// tc: O(n), sc: O(2*n) = O(n)

// optimal (Boyer-Moore Majority Vote Algorithm)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        /* 
        element2 is read in nums[i] != element2 before it is ever assigned, 
        since that check happens inside the count1 == 0 branch which triggers 
        on the very first iteration. This is undefined behavior, so both candidates 
        must be initialized to distinct sentinel values that won't appear in the input
        */
        int element1 = INT_MIN, element2 = INT_MAX, count1 = 0, count2 = 0;

        for (int i=0; i<n; i++) {
            if (count1 == 0 && nums[i] != element2) {
                count1 = 1;
                element1 = nums[i];
            }

            else if (count2 == 0 && nums[i] != element1) {
                count2 = 1;
                element2 = nums[i];
            }

            else if (nums[i] == element1) {
                count1++;
            }

            else if (nums[i] == element2) {
                count2++;
            }

            else {
                count1--, count2--;
            }
        }

        // verification
        int cnt1 = 0, cnt2 = 0;

        for (int i=0; i<n; i++) {
            if (nums[i] == element1) {
                cnt1++;
            } 

            else if (nums[i] == element2) { 
                cnt2++;
            }
        }

        vector<int> ans;

        if (cnt1 > (n/3)) {
            ans.push_back(element1);
        }

        if (cnt2 > (n/3)) {
            ans.push_back(element2);
        }

        return ans;
    }
};
// tc: O(2*n) = O(n), sc: O(1)
