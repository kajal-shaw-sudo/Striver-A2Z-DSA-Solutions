/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

1 
0 1 
1 0 1 
0 1 0 1 
1 0 1 0 1

Print the pattern in the function given to you.
*/

class Solution {
public:
    void pattern11(int n) {
        // 1st row starts by printing a single 1
        int start = 1;

        for (int i=0; i<n; i++) {
            // if row index is odd, print 0 first in the row, else if index is even, start with 1
            if (i % 2 == 1) {
                start = 0;
            }

            else {
                start = 1;
            }

            for (int j=0; j<=i; j++) {
                cout<<start;

                // Only print a space if it's NOT the last element in the row
                if (j < i) {
                    cout<<' ';
                }

                start = 1 - start;
            }

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)