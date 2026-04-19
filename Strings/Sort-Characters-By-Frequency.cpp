// problem: https://leetcode.com/problems/sort-characters-by-frequency/description/

// brute: count the frequency of each character and sort them based on frequency
class Solution {
private:
    static bool comparator(pair<char, int>& a, pair<char, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }

        return a.first < b.first;
    }

public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;

        for (char c : s) {
            mpp[c]++;
        }

        vector<pair<char, int>> freq(mpp.begin(), mpp.end());

        sort(freq.begin(), freq.end(), comparator);

        string ans = "";

        for (auto& p : freq) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};
// tc: O(nlogn), sc: O(n) where n is the length of the input string

// optimal: use a bucket sort approach where we create buckets based on frequency and then iterate through the buckets in reverse order to build the answer string
class Solution {public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;

        for (char c : s) {
            mpp[c]++;
        }

        int maxFreq = 0;

        for (auto& p : mpp) {
            maxFreq = max(maxFreq, p.second);
        }

        vector<string> buckets(maxFreq + 1);

        for (auto& p : mpp) {
            buckets[p.second] += string(p.second, p.first);
        }

        string ans = "";

        for (int i=maxFreq; i>=0; i--) {
            ans += buckets[i];
        }

        return ans;
    }
};
// tc: O(n), sc: O(n) where n is the length of the input string