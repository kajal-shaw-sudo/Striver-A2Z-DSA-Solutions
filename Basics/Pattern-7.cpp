/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

    *
   ***
  *****
 *******
*********


Print the pattern in the function given to you.
*/

class Solution {
public:
    void pattern7(int n) {
        for (int i=0; i<n; i++) {
            // (n-i-1) leading spaces
            for (int j=0; j<n-i-1; j++) {
                cout<<' ';
            }

            // (2*i+1) stars
            for (int j=0; j<2*i+1; j++) {
                cout<<'*';
            }

            // (n-i-1) trailing spaces (optional)
            /*
            for (int j=0; j<n-i-1; j++) {
                cout<<' ';
            }
            */

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)