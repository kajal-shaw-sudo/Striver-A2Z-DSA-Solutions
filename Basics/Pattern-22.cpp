/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5

Print the pattern in the function given to you.
*/

class Solution {
public:
    void pattern22(int n) {
        for (int i=0; i<2*n-1; i++) {
            for (int j=0; j<2*n-1; j++) {
                // find distance from top, left, bottom, right
                int top = i;
                int left = j;
                int bottom = (2 * n - 2) - i;
                int right = (2 * n - 2) - j;

                // take the min of all 4 distances
                int minDistance = min({top, bottom, left, right});

                // print the number which is n - minDistance (number starts with n at border, decreases inside)
                cout<<n - minDistance;

                // Only print a space between numbers, not after the last one
                if (j < 2 * n - 2) {
                    cout<<' ';
                }
            }

            cout<<'\n';
        }
    }
};
// tc: O(n^2), sc: O(1)