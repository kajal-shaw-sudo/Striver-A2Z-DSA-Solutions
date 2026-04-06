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