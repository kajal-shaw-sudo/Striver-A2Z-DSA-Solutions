// brute
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> ans;

        for (int i=1; i<=n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
// tc = O(n) , sc = O(n)

// optimal
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> ans;

        for (int i=1; i*i<=n; i++) {
            if (n % i == 0) {
                ans.push_back(i);

                // if n / i is not equal to i, then add n / i
                if (n / i != i) {
                    ans.push_back(n / i);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
// tc = O(sqrt(n) + klogk) [where k is the number of divisors of n for sorting] , sc = O(k)