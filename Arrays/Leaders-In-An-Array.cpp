// brute (for-loops)
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int n = nums.size();

      vector<int> ans;

      for (int i=0; i<n; i++) {
        bool leader = true;

        for (int j=i+1; j<n; j++) {
            if (nums[j] >= nums[i]) {
                leader = false;
                break;
            }
        }

        if (leader) {
            ans.push_back(nums[i]);
        }
      }

      return ans;
    }
};
// tc: O(n^2), sc: O(n)

// optimal (reverse traversal)
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int n = nums.size();

      vector<int> ans;

      ans.push_back(nums[n-1]);

      int maxi = nums[n-1];

      for (int i=n-2; i>=0; i--) {
        if (nums[i] > maxi) {
            ans.push_back(nums[i]);
            maxi = nums[i];
        }
      }

      reverse(ans.begin(), ans.end());

      return ans;
    }
};
// tc: O(n), sc: O(n)