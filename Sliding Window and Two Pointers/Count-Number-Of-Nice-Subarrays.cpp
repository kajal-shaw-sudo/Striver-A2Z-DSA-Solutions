// problem: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

// brute
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 0;

        for (int i=0; i<n; i++) {
            int odds = 0;

            for (int j=i; j<n; j++) {
                if (nums[j] % 2 == 1) {
                    odds++;
                }

                if (odds == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
// tc: O(n^2), sc: O(1)

// optimal: using prefix sum and hashing
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 0, odds = 0;

        unordered_map<int, int> freq;

        freq[0] = 1;

        for (int i=0; i<n; i++) {
            if (nums[i] % 2 == 1) {
                odds++;
            }

            if (freq.find(odds - k) != freq.end()) {
                count += freq[odds - k];
            }

            freq[odds]++;
        }

        return count;
    }
};
// tc: O(n), sc: O(n)
