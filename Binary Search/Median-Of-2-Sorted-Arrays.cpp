// problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

/*
problem: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

// brute: merge the two arrays and return the median of the merged array
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        vector<int> merged;

        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }

        while (i < n1) {
            merged.push_back(nums1[i++]);
        }

        while (j < n2) {
            merged.push_back(nums2[j++]);
        }

        int n = merged.size();

        if (n % 2 == 0) {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        } else {
            return merged[n / 2];
        }
    }
};
// tc: O(m + n), sc: O(m + n)

// better: walk through the two arrays up to the middle index and return the median based on the last two values seen
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        int n = n1 + n2;

        int i = 0, j = 0;

        int prev = -1, curr = -1;

        // We need to walk up to index n/2 in the merged order
        // That means looping (n/2 + 1) times
        for (int count=0; count<=n/2; count++) {
            prev = curr; // save last step's value before overwriting

            if (i < n1 && (j >= n2 || nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i++;
            }

            else {
                curr = nums2[j];
                j++;
            }
        }

        if (n % 2 == 0) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
    }
};
// tc: O(m + n), sc: O(1)

// optimal: using binary search, partition the two arrays into two halves such that the left half contains the smaller elements and the right half contains the larger elements, then return the median based on the maximum of the left half and the minimum of the right half
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1); // or, swap(nums1, nums2); swap(n1, n2); [cleaner and no stack frame used, but technically only 2 stack frames used in the recursive call anyway, so O(1) space complexity either way]
        }

        int n = n1 + n2;

        int low = 0, high = n1;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = (cut1 == 0 ? INT_MIN : nums1[cut1 - 1]);
            int l2 = (cut2 == 0 ? INT_MIN : nums2[cut2 - 1]);
            int r1 = (cut1 == n1 ? INT_MAX : nums1[cut1]);
            int r2 = (cut2 == n2 ? INT_MAX : nums2[cut2]);

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }

                else {
                    return (double)max(l1, l2);
                }
            }

            else if (l1 > r2) {
                high = cut1 - 1;
            }

            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
// tc: O(log(min(m, n))), sc: O(1)