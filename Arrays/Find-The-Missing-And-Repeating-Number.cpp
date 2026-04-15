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

// optimal