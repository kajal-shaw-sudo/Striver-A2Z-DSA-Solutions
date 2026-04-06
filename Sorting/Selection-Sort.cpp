class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }

        return nums;
    }
};
// tc = O(n^2) , sc = O(1) [in-place sorting]