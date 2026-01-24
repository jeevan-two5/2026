  #### I N T U I T I O N
    Maximum sum in circular array is either normal subarray or wrapped subarray.
    
    Use Kadane to find maximum subarray sum (normal case).
    
    Use Kadane again to find minimum subarray sum.
    
    Wrapped sum = total array sum − minimum subarray sum.
    
    If all elements are negative, return normal maximum.
    
    Answer = max(normal sum, wrapped sum).
#### C O D E     ====  O P T I M A L  ====          TIME : O ( N )  ::  SPACE: O(1) 
```cpp
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
            int totalSum = 0;
    int currMaxSum = 0, currMinSum = 0;
    int maxSum = arr[0], minSum = arr[0];

    for (int i = 0; i < arr.size(); i++) {

        // Kadane's to find maximum sum subarray
        currMaxSum = max(currMaxSum + arr[i], arr[i]);
        maxSum = max(maxSum, currMaxSum);

        // Kadane's to find minimum sum subarray
        currMinSum = min(currMinSum + arr[i], arr[i]);
        minSum = min(minSum, currMinSum);

        // Sum of all the elements of input array
        totalSum = totalSum + arr[i];
    }

    int normalSum = maxSum;
    int circularSum = totalSum - minSum;

    // If the minimum subarray is equal to total Sum
    // then we just need to return normalSum
    if (minSum == totalSum)
        return normalSum;

    return max(normalSum, circularSum);
    }
};
```
