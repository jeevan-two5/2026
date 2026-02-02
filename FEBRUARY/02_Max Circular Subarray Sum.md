#### I N T U I T I O N 
      Any circular max subarray is either
      (1) normal (no wrap) → use Kadane (max subarray)
      (2) wrapping → take total sum − minimum subarray
      
      Wrapping means: remove the worst (minimum) middle part.
      
      Edge case: if all numbers are negative, wrapping breaks → return normal max.
      
      👉 Final answer = max(normal_max, total_sum − min_subarray)
      
#### C O D E
```cpp
class Solution {
    
    int subarray_max(vector<int>arr){
        int n = arr.size();
        int csum = arr[0];
        int osum = arr[0];
        for(int i = 1; i<n;i++){
            if(csum >= 0){
                csum += arr[i];
                osum = max(csum, osum);
            }
            else{
                csum = arr[i];
                osum = max(csum, osum);
            }
        }
        return osum;
    }
    
    int subarray_min(vector<int> arr) {
        int n = arr.size();
        int csum = arr[0];
        int osum = arr[0];
    
        for(int i = 1; i < n; i++) {
            if(csum <= 0) {
                csum += arr[i];
            } else {
                csum = arr[i];
            }
            osum = min(osum, csum);
        }
        return osum;
    }
    
    int totsum(vector<int>&arr){
        int tot = 0; 
        for(int i = 0; i< arr.size();i++){
            tot += arr[i];
        }
        return tot;
    }
    
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int normal_sum = subarray_max(arr);
        int circular_sum = totsum(arr)-subarray_min(arr);
        
        if(totsum(arr) == subarray_min(arr)) return normal_sum;
        return max(normal_sum, circular_sum);
    }
};
```
