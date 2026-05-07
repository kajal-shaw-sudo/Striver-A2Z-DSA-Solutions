/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

*****
*   *
*   *
*   *
*****

Print the pattern in the function given to you.
*/

class Solution {
public:
    void pattern21(int n) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                // print star if it is a border cell
                if (i == 0 || j == 0 || i == n-1 || j == n-1) {
                    cout<<'*';
                }

                // print space otherwise
                else {
                    cout<<' ';
                }
            }

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)