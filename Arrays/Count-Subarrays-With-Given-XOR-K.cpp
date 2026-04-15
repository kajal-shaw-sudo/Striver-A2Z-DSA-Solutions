// brute
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();

        int count = 0;

        for (int i=0; i<n; i++) {
            int xorr = 0;

            for (int j=i; j<n; j++) {
                xorr ^= nums[j];

                if (xorr == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
// tc: O(n^2), sc: O(1)

// optimal (using hashing)
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();

        int xorr = 0, count = 0;

        unordered_map<int, int> freq;

        freq[0] = 1;

        for (int i=0; i<n; i++) {
            xorr ^= nums[i];

            int target = xorr ^ k;

            if (freq.find(target) != freq.end()) {
                count += freq[target];
            } else {
                freq[xorr]++;
            }
        }

        return count;
    }
};
// tc: O(n), sc: O(n)