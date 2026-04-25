/* 
Problem: There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.

The goal is to gather as much fruit as possible, adhering to the owner's stringent rules:

1) There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
2) Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
3) Once reaching a tree with fruit that cannot fit into any basket, stop.

Return the maximum number of fruits that can be picked.

Example 1

Input : fruits = [1, 2, 1]
Output : 3

Explanation : We will start from first tree.
The first tree produces the fruit of kind '1' and we will put that in the first basket.
The second tree produces the fruit of kind '2' and we will put that in the second basket.
The third tree produces the fruit of kind '1' and we have first basket that is already holding fruit of kind '1'. So we will put it in first basket.
Hence we were able to collect total of 3 fruits.

Example 2

Input : fruits = [1, 2, 3, 2, 2]
Output : 4

Explanation : we will start from second tree.
The first basket contains fruits from second , fourth and fifth.
The second basket will contain fruit from third tree.
Hence we collected total of 4 fruits.
*/

// brute: for-loops
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();

        int maxCount = 0;

        for (int i=0; i<n; i++) {
            unordered_map<int, int> basket;
            int currentCount = 0;

            for (int j=i; j<n; j++) {
                basket[fruits[j]]++;

                if (basket.size() > 2) {
                    break;
                }

                currentCount++;

                maxCount = max(maxCount, currentCount);
            }
        }

        return maxCount;
    }
};
// tc: O(n^2) sc: O(1) [at most 2 fruits in the basket]

// better: sliding window and hashmap
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();

        unordered_map<int, int> basket;

        int maxCount = 0;

        int left = 0, right = 0;

        while (right < n) {
            basket[fruits[right]]++;

            while (basket.size() > 2) {
                basket[fruits[left]]--;

                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }

                left++;
            }

            maxCount = max(maxCount, right-left+1);

            right++;
        }

        return maxCount;
    }
};
// tc: O(n) sc: O(1) [at most 2 fruits in the basket]

// optimal : sliding window and variables for distinct fruit count instead of hashmap
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();

        int lastFruit = -1, secondLastFruit = -1;

        int maxCount = 0;

        int currentCount = 0, lastFruitStreak = 0;

        for (int fruit : fruits) {
            if (fruit == lastFruit || fruit == secondLastFruit) {
                currentCount++;
            }

            else {
                currentCount = lastFruitStreak + 1;
            }

            if (fruit == lastFruit) {
                lastFruitStreak++;
            }

            else {
                lastFruitStreak = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }

            maxCount = max(maxCount, currentCount);
        }

        return maxCount;
    }
};
// tc: O(n) sc: O(1)
