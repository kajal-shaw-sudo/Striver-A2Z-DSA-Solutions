class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();

        for (int i=1; i<n; i++) {
            int key = nums[i];
            int j = i - 1;

            // shift elements greater than key to the right 
            while (j >= 0 && nums[j] > key) {
                nums[j+1] = nums[j];  // shift
                j--;
            }

            nums[j+1] = key;  // insert
        }

        return nums;
    }
};
// tc = O(n^2) [worst case when array is sorted in reverse order] , sc = O(1) [in-place sorting]