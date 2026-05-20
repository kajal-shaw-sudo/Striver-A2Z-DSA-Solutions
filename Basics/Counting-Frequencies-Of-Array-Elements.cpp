/*
problem: Given an array nums of size n which may contain duplicate elements.
Return a list of pairs where each pair contains a unique element from the array and its frequency in the array.
You may return the result in any order, but each element must appear exactly once in the output.

Example 1
Input: nums = [1, 2, 2, 1, 3]
Output: [[1, 2], [2, 2], [3, 1]]
Explanation:
- 1 appears 2 times
- 2 appears 2 times
- 3 appears 1 time
Order of output can vary.

Example 2
Input: nums = [5, 5, 5, 5]
Output: [[5, 4]]
Explanation:
- 5 appears 4 times.
*/

class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        // Your code goes here
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> ans;

        for (auto& it : freq) {
            ans.push_back({it.first, it.second});
        }

        return ans;
    }
};
// tc = O(n) [iteration to count frequencies] + O(m) [iteration to create ans vector, where m is number of unique elements in nums] = O(n), sc = O(m) [unordered_map to store frequencies] + O(m) [ans vector to store result] = O(m)