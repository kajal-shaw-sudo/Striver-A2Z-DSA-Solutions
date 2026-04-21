// brute
class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
        int n = nums.size();

        long long count = 0;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (nums[i] > nums[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};
// tc: O(n^2), sc: O(1)

// optimal (merge sort)
class Solution {
private:
    long long merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;

        long long count = 0;

        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }

            else {
                temp.push_back(nums[right]);
                count += (mid-left+1); // all remaining left elements are inversions
                right++;
            }
        }

        // if left half still has elements
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // if right half still has elements
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // copy back to merged elements back to original array
        for (int i=low; i<=high; i++) {
            nums[i] = temp[i-low];
        }

        return count;
    }

    long long mergeSort(vector<int>& nums, int low, int high) {
        long long count = 0;
        
        if (low >= high) {
            return count;
        }

        int mid = low + (high-low)/2;

        // count inversions in left half
        count += mergeSort(nums, low, mid);

        // count inversions in right half
        count += mergeSort(nums, mid+1, high);

        // count inversions during merge
        count += merge(nums, low, mid, high);

        return count;
    }

public:
   long long int numberOfInversions(vector<int> nums) {
        int n = nums.size();

        return mergeSort(nums, 0, n-1);
    }
};
// tc: O(n log n), sc: O(n) due to temp array used in merge function