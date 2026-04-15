// brute
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();

        int repeating = -1, missing = -1;

        for (int i=1; i<=n; i++) {
            int count = 0;

            for (int j=0; j<n; j++) {
                if (nums[j] == i) {
                    count++;
                }
            }

            if (count == 2) {
                repeating = i;
            }

            else if (count == 0) {
                missing = i;
            }

            if (repeating != -1 && missing != -1) {
                break;
            }
        }

        return  {repeating, missing};
    }
};
// tc: O(n^2), sc: O(1)

// better (using hashing)
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();

        unordered_map<int, int> freq;
        int repeating = -1, missing = -1;

        for (int num : nums) {
            freq[num]++;
        }

        for (int i=1; i<=n; i++) {
            if (freq[i] == 2) {
                repeating = i;
            }

            else if (freq[i] == 0) {
                missing = i;
            }

            if (repeating != -1 && missing != -1) {
                break;
            }
        }

        return {repeating, missing};
    }
};
// tc: O(n), sc: O(n)

// optimal 1: using sum
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();

        long long s1 = 0, s2 = 0, sn = 0, s2n = 0;

        sn = (n * (n+1)) / 2;
        s2n = (n * (n+1) * (2*n+1)) / 6;

        for (int i=0; i<n; i++) {
            s1 += nums[i];
            s2 += (long long)nums[i] * nums[i];
        }

        // x + y = (s21 - s2n) / (s - sn), x + y = s - sn
        long long xPlusY = (s2 - s2n) / (s1 - sn);
        long long xMinusY = (s1 - sn);

        int repeating = (xPlusY + xMinusY) / 2;
        int missing = (xPlusY - xMinusY) / 2; 

        return {repeating, missing};
    }
};
// tc: O(n), sc: O(1)

// optimal 2: using XOR 
