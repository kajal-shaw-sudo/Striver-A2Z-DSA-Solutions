// problem: https://leetcode.com/problems/two-sum/description/

// brute (for-loops)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};
// tc = O(n^2) , sc = O(1)

// better (2-pointers + sorting)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int, int>> v;
        for (int i=0; i<n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int left = 0, right = n-1;

        while (left <= right) {
            int sum = v[left].first + v[right].first;

            if (sum == target) {
                return {v[left].second, v[right].second};
            } 

            else if (sum < target) {
                left++;
            }

            else {
                right--;
            }
        }

        return {};
    }
};
// tc = O(n log n) , sc = O(n)

// optimal (hashing)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for (int i=0; i<n; i++) {
            int second = target - nums[i];

            if (mpp.find(second) != mpp.end()) {
                return {i, mpp[second]};
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};
// tc = O(n) , sc = O(n)