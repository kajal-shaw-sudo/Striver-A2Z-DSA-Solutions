/*
problem: Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.
Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.

Example 1
Input: nums = [12, 34, 67, 90], m=2
Output: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2
Input: nums = [25, 46, 28, 49, 24], m=4
Output: 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
*/

// brute: linear search: check every candidate answer from max(nums) to sum(nums) linearly. For each candidate page limit, greedily count the minimum students needed. Return the first limit where students needed ≤ m.
class Solution {
private:
    int countStudents(vector<int>& nums, int pages) {
        int students = 1;
        long long pagesStudent = 0;

        for (int i=0; i<nums.size(); i++) {
            if (pagesStudent + nums[i] <= pages) {
                pagesStudent += nums[i];
            }

            else {
                students++;
                pagesStudent = nums[i];
            }
        }

        return students;
    }
    
public:
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();

        if (m > n) {
            return -1;
        }

        int maxi = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        for (int pages=maxi; pages<=sum; pages++) {
            if (countStudents(nums, pages) <= m) {
                return pages;
            }
        }

        return -1;
    }
};
// tc: O(N * (S) [where S is the sum of nums], sc: O(1)

// optimal: binary search: binary search on the answer space [max(nums), sum(nums)]. For each mid, greedily check if books can be allocated to ≤ m students. Shrink right when valid (look for smaller), expand left otherwise.
class Solution {
private:
    int countStudents(vector<int>& nums, int pages) {
        int students = 1;
        long long pagesStudent = 0;

        for (int i=0; i<nums.size(); i++) {
            if (pagesStudent + nums[i] <= pages) {
                pagesStudent += nums[i];
            }

            else {
                students++;
                pagesStudent = nums[i];
            }
        }

        return students;
    }

public:
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();

        if (m > n) {
            return -1;
        }

        int maxi = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int low = maxi, high = sum;

        int ans = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countStudents(nums, mid) <= m) {
                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
// tc: O(N * log(S) [where S is the sum of nums] = O(N * log(S)), sc: O(1)

/*
Note: The problem requires contiguous allocation, meaning books must be assigned in their original array order — sorting would violate this constraint and solve a different problem entirely. The binary search is also not applied over the array; it's applied over the answer space [max(nums), sum(nums)], which is independent of element order. The array is only touched inside countStudents, which does a greedy left-to-right pass in original order — exactly as the problem demands.
*/