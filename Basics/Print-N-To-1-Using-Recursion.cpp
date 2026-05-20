/*
problem: Given an integer n, write a function to print all numbers from n to 1 (inclusive) using recursion.
You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in decreasing order from n to 1

Example 1
Input: 5
Output:
5
4
3
2
1

Example 2
Input: 1
Output:
1
*/

class Solution {
private:
    void solve(int n) {
        if (n == 0) {
            return;
        }

        cout<<n<<"\n";

        solve(n-1);
    }

  public:
    void printNumbers(int n) {
        // Your code goes here
        solve(n);
    }
};
// tc = O(n), sc = O(n) [stack]