/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

Print the pattern in the function given to you.
*/

class Solution {
public:
    void pattern17(int n) {
        for (int i=0; i<n; i++) {
            // print (n-i-1) leading spaces
            for (int j=0; j<n-i-1; j++) {
                cout<<' ';
            }

            char ch = 'A';

            // calculate midpoint of the row
            int midPoint = (2 * i + 1) / 2;

            for (int j=1; j<=2*i+1; j++) {
                cout<<ch;

                // increment character till the midpoint, then decrement 
                if (j <= midPoint) {
                    ch++;
                }

                else {
                    ch--;
                }
            }

            // print (n-i-1) trailing spaces (optional)
            /*
            for (int j=0; j<2*i+1; j++) {
                cout<<' ';
            }
            */

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)