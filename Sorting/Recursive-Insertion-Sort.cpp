class Solution {
private:
    void insertion_sort(vector<int>& nums, int n) {
        if (n <= 1) {
            return;
        }

        insertion_sort(nums, n-1);

        int last = nums[n-1];

        int j = n-2;

        while (j >= 0 && nums[j] > last) {
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = last;
    }

public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();

        insertion_sort(nums, n);

        return nums;
    }
};
// tc: O(n^2), sc: O(n) due to recursive stack space