/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********

Print the pattern in the function given to you.
*/

class Solution {
public:
    void pattern19(int n) {
        // upper half

        int spaces = 0;

        for (int i=0; i<n; i++) {
            // (n-i) stars
            for (int j=1; j<=n-i; j++) {
                cout<<'*';
            }

            // "spaces" spaces in middle
            for (int j=0; j<spaces; j++) {
                cout<<' ';
            }

            // (n-i) stars again
            for (int j=1; j<=n-i; j++) {
                cout<<'*';
            }

            spaces += 2;

            cout<<'\n';
        }

        // lower half

        spaces = 2 * n - 2;

        for (int i=0; i<n; i++) {
            // i stars
            for (int j=1; j<=i+1; j++) {
                cout<<'*';
            }

            // "spaces" spaces in middle
            for (int j=0; j<spaces; j++) {
                cout<<' ';
            } 

            // i stars again
            for (int j=1; j<=i+1; j++) {
                cout<<'*';
            }

            spaces -= 2;

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)