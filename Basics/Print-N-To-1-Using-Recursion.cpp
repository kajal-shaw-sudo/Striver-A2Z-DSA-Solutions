class Solution {
private:
    void solve(int n) {
        if (n == 0) {
            return;
        }

        cout<<n<<"\n";

        solve(n-1);
    }

  public:
    void printNumbers(int n) {
        // Your code goes here
        solve(n);
    }
};