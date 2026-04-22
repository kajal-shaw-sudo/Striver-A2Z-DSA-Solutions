class Solution {
private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];

        // initialize i to place smaller elements
        int i = low-1;

        for (int j=low; j<high; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        // place pivot in correct position
        swap(nums[i+1], nums[high]);

        // return the pivot index
        return i+1;
    }

    void quick_sort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }

        int pivotIndex = partition(nums, low, high);

        quick_sort(nums, low, pivotIndex-1);
        quick_sort(nums, pivotIndex+1, high);
    }

public:
    vector<int> quickSort(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return nums;
        }

        quick_sort(nums, 0, n-1);

        return nums;
    }
};
// tc: O(n log n) on average, O(n^2) in worst case (when the smallest or largest element is always chosen as pivot), sc: O(log n) on average, O(n) in worst case [skewed recursion like linked list] due to recursive stack space