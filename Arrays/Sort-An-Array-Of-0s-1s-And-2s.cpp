// problem: https://leetcode.com/problems/sort-colors/description/

// brute (sorting) 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
// tc: O(nlogn), sc: O(1)

// better (counting sort)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int zeros = 0, ones = 0;

        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                zeros++;
            } else if (nums[i] == 1) {
                ones++;
            }
        }

        for (int i=0; i<zeros; i++) {
            nums[i] = 0;
        }

        for (int i=zeros; i<zeros+ones; i++) {
            nums[i] = 1;
        }

        for (int i=zeros+ones; i<n; i++) {
            nums[i] = 2;
        }
    }
};
// tc: O(n), sc: O(1)

// optimal (Dutch National Flag Algorithm)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0, mid = 0, high = n-1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++, mid++;
            }

            else if (nums[mid] == 1) {
                mid++;
            }

            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
// tc: O(n), sc: O(1)
