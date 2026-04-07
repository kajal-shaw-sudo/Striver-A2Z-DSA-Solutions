class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};
// tc = O(n) , sc = O(1)