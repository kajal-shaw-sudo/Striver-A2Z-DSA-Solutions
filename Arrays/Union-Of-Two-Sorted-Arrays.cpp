// brute 1 (map)
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        map<int, int> mpp;

        for (int x : nums1) {
            mpp[x]++;
        }

        for (int x : nums2) {
            mpp[x]++;
        }

        for (auto& it : mpp) {
            ans.push_back(it.first);
        }

        return ans;
    }
};
// tc: O(n1 log n1 + n2 log n2), sc: O(n1 + n2)

// brute 2 (set)
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;

        for (int x : nums1) {
            st.insert(x);
        }

        for (int x : nums2) {
            st.insert(x);
        }

        return vector<int> (st.begin(), st.end());
    }
};
// tc: O(n1 log n1 + n2 log n2), sc: O(n1 + n2)

// optimal (2-pointers)
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        vector<int> ans;

        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }

                i++;
            } 

            else if (nums1[i] > nums2[j]) {
                if (ans.empty() || ans.back() != nums2[j]) {
                    ans.push_back(nums2[j]);
                }

                j++;
            }

            else {
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                
                i++, j++;
            }
        }

        while (i < n1) {
            if (ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }

            i++;
        }

        while (j < n2) {
            if (ans.empty() || ans.back() != nums2[j]) {
                ans.push_back(nums2[j]);
            }

            j++;
        }

        return ans;
    }
};
// tc: O(n1 + n2), sc: O(n1 + n2)