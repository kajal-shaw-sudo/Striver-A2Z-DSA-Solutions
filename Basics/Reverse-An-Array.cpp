// iteration
class Solution{
public:
    void reverse(int arr[], int n){
        int start = 0, end = n-1;

        while (start <= end) {
            swap(arr[start], arr[end]);

            start++, end--;
        }
    }
};
// tc = O(n/2) [iteration loop at most n/2 iterations] = O(n), sc = O(1)

// recursion
class Solution{
private:
    void solve(int arr[], int start, int end) {
        if (start >= end) {
            return;
        }

        swap(arr[start], arr[end]);

        solve(arr, start+1, end-1);
    }
    
public:
    void reverse(int arr[], int n){
        solve(arr, 0, n-1);
    }
};
// tc = O(n/2) = O(n), sc = O(n/2) [recursion stack space at most n/2 calls] = O(n)