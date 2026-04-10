// brute
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();

        int maxi = 0;

        for (int i=0; i<n; i++) {
            int sum = 0;

            for (int j=i; j<n; j++) {
                sum += nums[j];

                if (sum > k) {
                    break;
                }

                if (sum == k) {
                    maxi = max(maxi, j-i+1);
                }
            }
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(1)

// optimal (sliding window)
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();

        int maxi = 0, sum = 0;
        int left = 0, right = 0;

        while (right < n) {
            sum += nums[right];

            while (left <= right && sum > k) {
                sum -= nums[left];
                left++;
            }

            if (sum == k) {
                maxi = max(maxi, right-left+1);
            }

            right++;
        }

        return maxi;
    }
};
// tc: O(2*n) = O(n), sc: O(1)