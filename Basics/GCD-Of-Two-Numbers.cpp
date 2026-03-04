// euclid approach
class Solution {
public:
    int GCD(int n1,int n2) {
        while (n1 > 0 && n2 > 0) {
            if (n1 > n2) {
                n1 = n1 % n2;
            } else {
                n2 = n2 % n1;
            }
        }

        if (n1 == 0) {
            return n2;
        }
        
        if (n2 == 0) {
            return n1;
        }
    }
};
// tc = O(log(min(n1, n2))


// ceaner euclid
class Solution {
public:
    int GCD(int n1,int n2) {
        while (n1 != 0) {
            int temp = n2;
            n2 = n1 % n2;
            n1 = temp;
        }

        return n1;
    }
};
// tc = O(log(min(n1, n2))