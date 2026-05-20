/*
problem: Given an integer n, write a function to print all numbers from 1 to n (inclusive) using recursion.
You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in increasing order from 1 to n.

Example 1
Input: n = 5
Output:
1  
2  
3  
4  
5

Example 2
Input: n = 1
Output:
1
*/

class Solution {
private:
    void solve(int n) {
        if (n == 0) {
            return;
        }

        solve(n-1);

        cout<<n<<"\n";
    }

  public:
    void printNumbers(int n) {
        // Your code goes here
        solve(n);
    }
};
// tc = O(n), sc = O(n) [stack]