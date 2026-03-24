// brute: using loop
class Solution{	
	public:
		int NnumbersSum(int N){
			//your code goes here

            int sum = 0;

            for (int i=1; i<=N; i++) {
                sum += i;
            }

            return sum;
		}
};
// tc = O(n), sc = O(1)

// using formula: n(n+1)/2
class Solution{	
	public:
		int NnumbersSum(int N){
			//your code goes here

            return N * (N +1) / 2;
		}
};
// tc = O(1), sc = O(1)

// recursion 1
class Solution{	
    private:
        int solve(int N, int sum) {
            if (N == 0) {
                return sum;
            }

            return solve(N-1, sum + N);
        }

	public:
		int NnumbersSum(int N){
			//your code goes here

            return solve(N, 0);
		}
};
// tc = O(n), sc = O(n) [stack]

// recursion 2
class Solution{	
    private:
        int solve(int N) {
            if (N == 0) {
                return 0;
            }

            return N + solve(N-1);
        }

	public:
		int NnumbersSum(int N){
			//your code goes here

            return solve(N);
		}
};
// tc = O(n), sc = O(n) [stack]