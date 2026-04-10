// brute
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();

        int length = 0, maxi = 0;

        for (int i=0; i<n; i++) {
            int sum = 0;

            for (int j=i; j<n; j++) {
                sum += nums[j];

                if (sum == k) {
                    length = j-i+1;

                    maxi = max(maxi, length);
                }
            }
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(1)

// optimal (prefix sum + hashmap)
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();

        unordered_map<int, int> mpp;

        int sum = 0, maxi = 0;

        for (int i=0; i<n; i++) {
            sum += nums[i];

            if (sum == k) {
                maxi = i + 1;
            }

            if (mpp.find(sum-k) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum-k]);
            } 

            // store first occurrence only
            if (mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }

        return maxi; 
    }
};
// tc: O(n), sc: O(n)