/*
problem: Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

12345
1234
123
12
1

Print the pattern in the function given to you.
*/


class Solution {
public:
    void pattern6(int n) {
        for (int i=0; i<n; i++) {
            for (int j=n; j>i; j--) {
                cout<<n-j+1;
            }

            cout<<'\n';
        }
    }
};