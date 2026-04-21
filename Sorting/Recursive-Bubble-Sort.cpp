class Solution {
private:
    void bubble_sort(vector<int>& nums, int n) {
        if (n == 1) {
            return;
        }

        bool didSwap = false;

        for (int i=0; i<n-1; i++) {
            if (nums[i] > nums[i+1]) {
                swap(nums[i], nums[i+1]);
                didSwap = true;
            }
        }

        if (!didSwap) {
            return;
        }

        bubble_sort(nums, n-1);
    }

public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();

        bubble_sort(nums, n);

        return nums;
    }
};
// tc: O(n^2), sc: O(n) due to recursive stack space