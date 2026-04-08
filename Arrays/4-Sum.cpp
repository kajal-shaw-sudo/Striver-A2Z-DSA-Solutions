// problem: https://leetcode.com/problems/4sum/description/

// brute (for-loops)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> st;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    for (int l=k+1; l<n; l++) {
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        if ((int)sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        return vector<vector<int>> (st.begin(), st.end());
    }
};
// tc: O(n^4 log n) (because of sorting the temp vector and inserting into set), sc: O(n^4) (because of the set storing all the quadruplets)

// better (hashing)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> st;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                unordered_set<long long> hash;

                for (int k=j+1; k<n; k++) {
                    long long fourth = (long long)target - ((long long)nums[i] + nums[j] + nums[k]);

                    if (hash.find(fourth) != hash.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }

                    hash.insert((long long)nums[k]);
                }
            }
        }

        return vector<vector<int>> (st.begin(), st.end());
    }
};
// tc: O(n^3 log n) (because of sorting the temp vector and inserting into set), sc: O(n^3) (because of the set storing all the quadruplets and the hash set storing the elements for each pair of i and j)

// optimal (two pointers + sorting)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i=0; i<n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            for (int j=i+1; j<n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int k = j+1, l = n-1;

                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;

                        while (k < l && nums[k] == nums[k-1]) {
                            k++;
                        }

                        while (k < l && nums[l] == nums[l+1]) {
                            l--;
                        }
                    }

                    else if (sum < target) {
                        k++;
                    }

                    else {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};
// tc: O(n^3) (because of the three nested loops), sc: O(1) (ignoring the space used for the answer vector)