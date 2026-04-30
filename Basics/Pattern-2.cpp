/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

*
**
***
****
*****

Print the pattern in the function given to you.
*/

// approach 1 (preferable in interview)
class Solution {
public:
    void pattern2(int n) {
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                cout<<'*';
            }

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)

// approach 2
class Solution {
public:
    void pattern2(int n) {
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                cout<<'*';
            }

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)