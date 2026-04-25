// problem link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

/*
problem: There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
*/

// brute: two for-loops to try all combinations of left and right cards 
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int maxScore = 0;

        for (int leftCount=0; leftCount<=k; leftCount++) {
            int rightCount = k - leftCount;

            int sum = 0;

            for (int i=0; i<leftCount; i++) {
                sum += cardPoints[i];
            }

            for (int i=0; i<rightCount; i++) {
                sum += cardPoints[n-1-i];
            }

            maxScore = max(maxScore, sum);
        }

        return maxScore;
    }
};
// tc: O(k^2) sc: O(1)

// better: prefix sums and suffix sums
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        vector<int> prefix(k+1, 0), suffix(k+1, 0);

        for (int i=1; i<=k; i++) {
            prefix[i] = prefix[i-1] + cardPoints[i-1];
            suffix[i] = suffix[i-1] + cardPoints[n-i];
        }

        int maxScore = 0;

        for (int i=0; i<=k; i++) {
            maxScore = max(maxScore, prefix[i] + suffix[k-i]); // i from left, k-i from right
        }

        return maxScore;
    }
};
// tc: O(k) sc: O(k)

// optimal: sliding window — start with k cards from front, then slide the selection rightward by replacing front cards with back cards one at a time
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = 0;

        // calculate initial sum by taking k cards from front
        for (int i=0; i<k; i++) {
            total += cardPoints[i];
        }

        int maxScore = total;

        // move window from front to back k times
        for (int i=0; i<k; i++) {
            // subtract card from front
            total -= cardPoints[k-1-i];

            // add card from back
            total += cardPoints[n-1-i];

            maxScore = max(maxScore, total);
        }

        return maxScore;
    }
};
// tc: O(k) sc: O(1)