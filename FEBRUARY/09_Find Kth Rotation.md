##### I N T U I T I O N
    In a rotated sorted array, the index of the minimum element equals the number of right rotations.
    Binary search is used to locate this minimum by comparing arr[mid] with the last element—if greater, the minimum lies right; otherwise, it lies left (or at mid).

  ##### C O D E
```cpp
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        // If array is already sorted
        if (arr[low] <= arr[high])
            return 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the minimum
            if (mid > 0 && arr[mid] < arr[mid - 1])
                return mid;

            // Decide which half to search
            if (arr[mid] >= arr[0])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
};

```
