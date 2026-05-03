/*
problm: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

1        1
12      21
123    321
1234  4321
1234554321

Print the pattern in the function given to you.
*/

class Solution {
public:
    void pattern12(int n) {
        // initial spaces in the middle for the first row
        int spaces = 2 * (n-1);
        
        for (int i=1; i<=n; i++) {
            // print numbers in increasing order
            for (int j=1; j<=i; j++) {
                cout<<j;
            }

            // print spaces in the middle
            for (int j=1; j<=spaces; j++) {
                cout<<' ';
            }

            // print numbers in the decreasing order
            for (int j=i; j>=1; j--) {
                cout<<j;
            }

            cout<<'\n';

            spaces -= 2;
        }
    }
};
// tc: O(n^2), sc: O(1)