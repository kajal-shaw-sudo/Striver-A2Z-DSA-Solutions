class Solution {
public:
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }

        return n * factorial(n-1);
    }
};
// tc = O(n), sc = O(n) [stack]
