// problem: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

// brute
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 0;

        for (int i=0; i<n; i++) {
            unordered_set<int> seen;

            for (int j=i; j<n; j++) {
                if (!seen.count(nums[j])) {
                    seen.insert(nums[j]);
                }

                if (seen.size() == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
// tc: O(n^2), sc: O(n)

// optimal: using sliding window
class Solution {
private:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        int count = 0, l = 0, r = 0;

        while (r < n) {
            freq[nums[r]]++;

            while (freq.size() > k) {
                freq[nums[l]]--;

                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }

                l++;
            }

            count += (r - l + 1);

            r++;
        }

        return count;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
};
// tc: O(n), sc: O(n)