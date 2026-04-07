// stl
class Solution {
public:
    int largestElement(vector<int>& nums) {
        return *max_element(nums.begin(), nums.end());
    }
};
// tc = O(n) , sc = O(1)

// sorting
class Solution {
public:
    int largestElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return nums[n-1];
    }
};
// tc = O(nlogn) , sc = O(1)

// iterative
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
            }
        }

        return maxi;
    }
};
// tc = O(n) , sc = O(1)