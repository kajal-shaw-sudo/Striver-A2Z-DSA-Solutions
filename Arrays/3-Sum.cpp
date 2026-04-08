// problem: https://leetcode.com/problems/3sum/description/

// brute (for-loops)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        return vector<vector<int>> (st.begin(), st.end());
    }
};
// tc = O(n^3 log n) , sc = O(n^2) [set vectors]

// better (hashing)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> st;

        for (int i=0; i<n; i++) {
            unordered_set<int> hash;

            for (int j=i+1; j<n; j++) {
                int third = -(nums[i] + nums[j]);

                if (hash.find(third) != hash.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }

                hash.insert(nums[j]);
            }
        }

        return vector<vector<int>> (st.begin(), st.end());
    }
};
// tc = O(n^2 log n) , sc = O(n)

// optimal (2-pointers + sorting)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i=0; i<n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j = i+1, k = n-1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;

                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }

                    while (j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }

                else if (sum < 0) {
                    j++;
                }

                else {
                    k--;
                }
            }
        }

        return ans;
    }
};
// tc = O(n^2) , sc = O(1) (ignoring the space for answer)
