class Solution {
private:
    void solve(int n) {
        if (n == 0) {
            return;
        }

        solve(n-1);

        cout<<n<<"\n";
    }

  public:
    void printNumbers(int n) {
        // Your code goes here
        solve(n);
    }
};