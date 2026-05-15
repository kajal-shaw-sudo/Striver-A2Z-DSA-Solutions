/*
problem: Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

Example 1
Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Example 2
Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Final sorted array is - [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892], 7th element of this array is 256.
*/

// brute: merge the two arrays and return the k-1 indexed element
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();

        vector<int> merged;

        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (a[i] <= b[j]) {
                merged.push_back(a[i]);
                i++;
            }

            else {
                merged.push_back(b[j]);
                j++;
            }
        }

        while (i < n1) {
            merged.push_back(a[i]);
            i++;
        }

        while (j < n2) {
            merged.push_back(b[j]);
            j++;
        }

        int n = merged.size();

        return merged[k-1];
    }
};
// tc: O(m + n), sc: O(m + n)

// optimal: using binary search, we can find the kth element in O(log(min(m, n))) time by performing binary search on the smaller array and calculating the corresponding index in the larger array. We check if the elements at these indices satisfy the conditions for being the kth element and adjust our search space accordingly.
