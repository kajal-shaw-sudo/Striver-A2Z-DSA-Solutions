// problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// brute (2-pass)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};
// tc: O(n^2), sc: O(1)

// optimal (1-pass)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;
        int buy = prices[0];

        for (int i=1; i<n; i++) {
            int profit = prices[i] - buy;
            maxProfit = max(maxProfit, profit);
            buy = min(buy, prices[i]);
        }

        return maxProfit;
    }
};
// tc: O(n), sc: O(1)
