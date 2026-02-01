####  I N T U I T I O N
    The cost of each subarray is its first element.
    
    To minimize total cost, keep the smallest numbers as starting points of subarrays.
    
    First subarray must start at nums[0]; for the remaining 2 subarrays, choose the two smallest elements from the rest.
    
    Sum = nums[0] + smallest two of nums[1…n-1].
####  C O D E

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum = nums[0];
        int n =  nums.size();
          vector<int>a1;
          for(int i = 1; i< n; i++){
            a1.push_back(nums[i]);
          }
          sort(a1.begin(),a1.end());

          sum = sum + a1[0] + a1[1];

          return sum;
    }
};
```
