/*
problem: You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:
Each painter paints only contiguous segments of boards.
No board can be split between painters.
The goal is to minimize the time to paint all boards.
Return the minimum time required to paint all boards modulo 10000003.

Example 1
Input: A = 2, B = 5, C = [1, 10]
Output: 50
Explanation:
Painter 1 paints board 0 (length = 1), time = 5
Painter 2 paints board 1 (length = 10), time = 50
Max time = 50
Return 50 % 10000003 = 50

Example 2
Input: A = 10, B = 1, C = [1, 8, 11, 3]
Output: 11
Explanation:
Assign each board to a different painter 
Max time = max(1, 8, 11, 3) = 11
Return 11 % 10000003 = 11
*/

// brute: linear search: check every candidate answer from max(C) to sum(C) linearly. For each candidate time, greedily count the minimum painters needed. Return the first time where painters needed ≤ A.
class Solution {
private:
    int countPainters(vector<int>& boards, int time) {
        int painters = 1;
        long long painterBoardLength = 0;

        for (int i=0; i<boards.size(); i++) {
            if (painterBoardLength + boards[i] <= time) {
                painterBoardLength += boards[i];
            }

            else {
                painters++;
                painterBoardLength = boards[i];
            }
        }

        return painters;
    }

public:
    int paint(int A, int B, vector<int>& C) {
        // Your code goes here
        int MOD =  10000003;

        int maxi = *max_element(C.begin(), C.end());
        int sum = accumulate(C.begin(), C.end(), 0);


        for (int time=maxi; time<=sum; time++) {
            if (countPainters(C, time) <= A) {
                return (long long)time * B % MOD;
            }
        }

        return -1;
    }
};
// tc: O(N * S [where S is the sum(C)], sc: O(1)

// optimal: binary search: binary search on the answer space [max(C), sum(C)]. For each mid, greedily check if boards can be painted by ≤ A painters. Shrink right when valid (look for smaller), expand left otherwise.
class Solution {
private:
    int countPainters(vector<int>& boards, int time) {
        int painters = 1;
        long long painterBoardLength = 0;

        for (int i=0; i<boards.size(); i++) {
            if (painterBoardLength + boards[i] <= time) {
                painterBoardLength += boards[i];
            }

            else {
                painters++;
                painterBoardLength = boards[i];
            }
        }

        return painters;
    }

public:
    int paint(int A, int B, vector<int>& C) {
        // Your code goes here
        int MOD =  10000003;

        int maxi = *max_element(C.begin(), C.end());
        int sum = accumulate(C.begin(), C.end(), 0);


        int low = maxi, high = sum;

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countPainters(C, mid) <= A) {
                ans = (long long)mid * B % MOD;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
// tc: O(N * log(S)) [where S is the sum(C)], sc: O(1)