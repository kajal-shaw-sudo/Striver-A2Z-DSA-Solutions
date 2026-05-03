/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

*********
 *******
  *****
   ***
    *

Print the pattern in the function given to you.
*/


class Solution {
public:
    void pattern8(int n) {
        for (int i=0; i<n; i++) {
            // i leading spaces (increases with row number)
            for (int j=0; j<i; j++) {
                cout<<' ';
            }

            // (2*n - (2*i+1)) stars (decreases with row number)
            for (int j=0; j<2*n-(2*i+1); j++) {
                cout<<'*';
            }

            // i trailing spaces (increases with row number) (optional)
            /*
            for (int j=0; j<i; j++) {
                cout<<' ';
            }
            */

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)
