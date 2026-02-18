###### C O D E
```cpp
class Solution {
  public:
  long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left;      // Starting index for left subarray
        int j = mid + 1;   // Starting index for right subarray
        long long count = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                // Inversion found: arr[i] > arr[j]
                // All elements from arr[i] to arr[mid] are greater than arr[j]
                temp.push_back(arr[j++]);
                count += (mid - i + 1);
            }
        }

        // Copy remaining elements
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        // Copy back to original array
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }

        return count;
    }

    long long mergeSort(vector<int>& arr, int left, int right) {
        long long count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            count += mergeSort(arr, left, mid);          // Left half
            count += mergeSort(arr, mid + 1, right);     // Right half
            count += mergeAndCount(arr, left, mid, right); // Merge step
        }
        return count;
        
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        return (int)mergeSort(arr, 0, arr.size() - 1);
    }
//  GFG(NOT DONE - (HAVE TO DO))
};```
