// brute
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        int maxi = 1;

        for (int i=0; i<n; i++) {
            int x = nums[i];

            int count = 1;

            while (nums, x+1) {
                x++;
                count++;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(1)

// better
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int maxi = 1, count = 1;

        for (int i=0; i<n-1; i++) {
            if (nums[i] + 1 == nums[i+1]) {
                count++;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};
// tc: O(nlogn), sc: O(1)

// optimal: using hashing
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        unordered_set<int> st;

        int maxi = 1;

        for (int num : nums) {
            st.insert(num);
        }

        for (auto& it : st) {
            // if it is the starting number of the sequence
            if (st.find(it-1) == st.end()) {
                int x = it;

                int count = 1;

                while (st.find(x+1) != st.end()) {
                    x++;
                    count++;
                }

                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};
// tc: O(n), sc: O(n)