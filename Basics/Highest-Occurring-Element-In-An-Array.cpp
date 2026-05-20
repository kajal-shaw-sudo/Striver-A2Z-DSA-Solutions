/*
problem: Given an array nums of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.
Please note that this section might seem a bit difficult without prior knowledge on what hashing is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!

Example 1
Input: nums = [1, 2, 2, 3, 3, 3]
Output: 3
Explanation: The number 3 appears the most (3 times). It is the most frequent element.

Example 2
Input: nums = [4, 4, 5, 5, 6]
Output: 4
Explanation: Both 4 and 5 appear twice, but 4 is smaller. So, 4 is the most frequent element.
*/

class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int maxFreq = INT_MIN;
        int ans = INT_MAX;

        for (auto& it : freq) {
            if (maxFreq < it.second) {
                maxFreq = it.second;
                ans = it.first;
            } 

            else if (it.second == maxFreq) {
                ans = min(ans, it.first);
            }
        }

        return ans;
    }
};
// tc = O(n) [iteration to count frequencies] + O(m) [iteration to find max frequency, where m is number of unique elements in nums] = O(n), where m <= n 
// sc = O(m) [unordered_map to store frequencies] = O(m), where m <= n -> O(n) in the worst case when all elements are unique