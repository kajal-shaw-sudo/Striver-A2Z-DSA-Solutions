// problem: https://leetcode.com/problems/maximum-product-subarray/description/

// brute (generate all subarrays) (3-pass)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                int product = 1;

                for (int k=i; k<=j; k++) {
                    product *= nums[k];

                    maxi = max(maxi, product);
                }
            }
        }

        return maxi;
    }
};
// tc: O(n^3), sc: O(1)

// slightly better (generate all subarrays) (2-pass)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            int product = 1;

            for (int j=i; j<n; j++) {
                product *= nums[j];

                maxi = max(maxi, product);
            }
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(1)

// better (prefix product)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int currMax = 1, currMin = 1, maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            int currProduct = currMax * nums[i];
            // curMin * nums[i] is the key term. When nums[i] is negative, multiplying by curMin (which is also negative) gives a large positive — which could become the new curMax.
            currMax = max({nums[i], currProduct, currMin * nums[i]});
            currMin = min({nums[i], currProduct, currMin * nums[i]});
            maxi = max(maxi, currMax);
        }

        return maxi;
    }
};
// tc: O(n), sc: O(1)

// optimal 1 (Kadane's Algorithm for Product)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1, suffix = 1, maxi = INT_MIN;

        for (int i=0; i<n; i++) {
            prefix *= nums[i];

            suffix *= nums[n-1-i];

            maxi = max({maxi, prefix, suffix});

            if (prefix == 0) {
                prefix = 1;
            }

            if (suffix == 0) {
                suffix = 1;
            }
        }

        return maxi;
    }
};
// tc: O(n), sc: O(1)

// optimal 2
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd = nums[0], minProd = nums[0], maxi = nums[0];

        for (int i=1; i<n; i++) {
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            maxi = max(maxi, maxProd);
        }

        return maxi;
    }
};
// tc: O(n), sc: O(1)
