// problem link: https://leetcode.com/problems/kth-missing-positive-number/description/

/*
problem: Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

// brute: linear search from 0 to n-1, return the smallest number such that the count of missing numbers before it is >= k
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        for (int i=0; i<n; i++) {
            if (arr[i] <= k) {
                k++;
            }

            else {
                // stop when we reach a number greater than k
                break;
            }
        }

        return k;
    }
};
// tc: O(n), sc: O(1)

// optimal: using binary search, return the smallest number such that the count of missing numbers before it is >= k
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // find the number of missing numbers from the actual value to expected value
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return k + high + 1;
    }
};
// tc: O(log(n)), sc: O(1)