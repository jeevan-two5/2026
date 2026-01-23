      ## I N T U I T I O N ##
    We want the maximum product subarray.
    
    Multiply numbers while moving left to right and keep the best answer.
    
    If product becomes 0, reset because subarray must restart.
    
    Do the same right to left to handle negative numbers.
    
    The maximum from both passes is the answer.
``` cpp
int maxprodsubarray(vector<int>&nums){
  int ans = INT_MIN;
  int cprod = 1;
  for(int i = 0; i < nums.size(); i++){
    cprod *= nums[i];
     ans = max(ans, cprod);
    if(cprod == 0) cprod = 1;
  }
  cprod = 1 ;
  for(int i = nums.size() ; i >=0 ; i--){
    ans = max(ans, cprod);
    if(cprod == 0) cprod = 1 ;
  }
  return ans ; 
}
```
