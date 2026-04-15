// brute 
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();

        int maxi = 0;

        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                sum += arr[j];

                if (sum == 0) {
                    maxi = max(maxi, j-i+1);
                }
            }
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(1)

// optimal (using hashing)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mpp;

        int maxi = 0, sum = 0;

        for (int i=0; i<n; i++) {
            sum += arr[i];

            if (sum == 0) {
                maxi = i+1;
            } else {
                if (mpp.find(sum) != mpp.end()) {
                    maxi = max(maxi, i - mpp[sum]);
                } else {
                    mpp[sum] = i;
                }
            }
        }

        return maxi;
    }
};
// tc: O(n), sc: O(n)