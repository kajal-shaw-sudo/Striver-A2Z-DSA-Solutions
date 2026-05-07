// problem link: https://leetcode.com/problems/koko-eating-bananas/description/

/*
problem: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30
*/

// brute: linear search from 1 to max(piles), return the smallest k such that sum of ceil(piles[i] / k) <= h
class Solution {
private:
    long long calculateHours(vector<int>& piles, int k) {
        long long hours = 0;

        for (int i=0; i<piles.size(); i++) {
            hours += ((long long)piles[i] + k - 1) / k;
        }

        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxi = *max_element(piles.begin(), piles.end());

        for (int k=1; k<=maxi; k++) {
            long long hoursTaken = calculateHours(piles, k);

            if (hoursTaken <= h) {
                return k;
            }
        }

        return maxi;
    }
};
// tc: O(n * max(piles)), sc: O(1)

// optimal: using binary search from 1 to max(piles), return the smallest k such that sum of ceil(piles[i] / k) <= h
class Solution {
private: 
    long long calculateHours(vector<int>& piles, int k) {
        long long hours = 0;

        for (int i=0; i<piles.size(); i++) {
            hours += ((long long)piles[i] + k - 1) / k;
        }

        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(); 

        int maxi = *max_element(piles.begin(), piles.end());

        int low = 1, high = maxi;

        int ans = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hoursTaken = calculateHours(piles, mid);

            if (hoursTaken <= h) {
                ans = mid;
                high = mid - 1;;
            }

            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
// tc: O(n * log(max(piles))), sc: O(1)