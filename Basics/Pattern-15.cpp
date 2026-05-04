/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

ABCDE
ABCD
ABC
AB
A

Print the pattern in the function given to you.
*/

// Approach 1 (recommended)
class Solution {
public:
    void pattern15(int n) {
        for (int i=n-1; i>=0; i--) {
            for (char ch='A'; ch<='A'+i; ch++) {
                cout<<ch;
            }

            cout<<'\n';
        }
    }
};

// Approach 2
class Solution {
public:
    void pattern15(int n) {
        for (int i=0; i<n; i++) {
            for (char ch='A'; ch<='A'+(n-i-1); ch++) {
                cout<<ch;
            }

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)