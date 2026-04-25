/*
problem: You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.
Return the count of occurrences of target in the array.

Example 1

Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1
Output: 3
Explanation: The number 1 appears 3 times in the array.
*/

// brute: linear search to count occurrences
class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        int n = arr.size();

        int count = 0;
        
        for (int i=0; i<n; i++) {
            if (arr[i] == target) {
                count++;
            }
        }

        return count;
    }
};
// tc: O(n), sc: O(1)

// optimal: binary search to find first and last occurrences
class Solution {
private:
    int findFirstOccurrence(vector<int>& arr, int target) {
        int firstOccurrence = -1;

        int left = 0, right = arr.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (arr[mid] >= target) {
                firstOccurrence = mid;
                right = mid - 1;
            }

            else {
                left = mid + 1;
            }
        }

        return firstOccurrence;
    }

    int findLastOccurrence(vector<int>& arr, int target) {
        int lastOccurrence = -1;

        int left = 0, right = arr.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (arr[mid] <= target) {
                lastOccurrence = mid;
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return lastOccurrence;
    }

public:
    int countOccurrences(vector<int>& arr, int target) {
        int firstOccurrence = findFirstOccurrence(arr, target);
        int lastOccurrence = findLastOccurrence(arr, target);

        if (firstOccurrence == -1 || arr[firstOccurrence] != target) {
            return 0;
        }

        return lastOccurrence - firstOccurrence + 1;
    }
};
// tc: O(log n), sc: O(1)