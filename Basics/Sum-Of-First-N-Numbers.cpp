class Solution{	
    private:
        int solve(int n, int sum) {
            if (n == 0) {
                return sum;
            }

            return solve(n-1, sum + n);
        }

	public:
		int NnumbersSum(int N){
			//your code goes here

            return solve(N, 0);
		}
};