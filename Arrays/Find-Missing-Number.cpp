// brute (for-loops) 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<=n; i++) {
            bool found = false;

            for (int j=0; j<n; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return i;
            }
        }

        return -1;
    }
};
// tc: O(n^2), sc: O(1)

// optimal 1 (sum) 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // sum1 = sum of array elements, sum2 = sum from 0 to n
        int sum1 = 0, sum2 = 0;

        for (int i=0; i<n; i++) {
            sum1 += nums[i];
            sum2 += i;
        }

        sum2 += n;

        return (sum2 - sum1);
    }
};
// tc: O(n), sc: O(1)

// optimal 2 (XOR)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // xor1 = xor of array elements, xor2 = xor from 0 to n
        int xor1 = 0, xor2 = 0;

        for (int i=0; i<n; i++) {
            xor1 ^= nums[i];
            xor2 ^= i;
        }

        xor2 ^= n;

        return (xor1 ^ xor2);
    }
};
// tc: O(n), sc: O(1)