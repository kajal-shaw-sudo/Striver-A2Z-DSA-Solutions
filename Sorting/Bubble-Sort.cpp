class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n-1-i; j++) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }

        return nums;
    }
};
// tc = O(n^2) , sc = O(1) [in-place sorting]