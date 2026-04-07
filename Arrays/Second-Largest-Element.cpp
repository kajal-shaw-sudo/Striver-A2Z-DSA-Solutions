// brute (sorting)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return -1;
        }

        sort(nums.begin(), nums.end());

        int maxi = nums[n-1];

        for (int i=n-2; i>=0; i--) {
            if (nums[i] < maxi) {
                return nums[i];
            }
        }

        return -1;
    }
};
// tc = O(n logn) , sc = O(1)

// better (two iterations)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return -1;
        }

        int maxi = *max_element(nums.begin(), nums.end()); 
        int second_max = INT_MIN;

        for (int i=0; i<n; i++) {
            if (nums[i] > second_max && nums[i] != maxi) {
                second_max = nums[i];
            }
        }

        return (second_max == INT_MIN ? -1 : second_max);
    }
};
// tc = O(2*n) = O(n) , sc = O(1)

// optimal (one iteration)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) {
            return -1;
        }

        int maxi = INT_MIN, second_max = INT_MIN;

        for (int i=0; i<n; i++) {
            if (nums[i] > maxi) {
                second_max = maxi;
                maxi = nums[i];
            }
            
            else if (nums[i] > second_max && nums[i] != maxi) {
                second_max = nums[i];
            }
        }

        return (second_max == INT_MIN ? -1 : second_max);
    }
};
// tc = O(n) , sc = O(1)