    ##  I N T U I T I O N  ##
    This is Kadane’s Algorithm.
    
    csum = best subarray sum ending at current index.
    
    If csum becomes negative, it’s useless → start fresh from current element.
    
    osum always stores the maximum sum seen so far.
    
    Final answer is the largest subarray sum.

    
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int csum = nums[0];
        int osum = nums[0];
        for(int i = 1;i<n;i++){
            if(csum >= 0){
            csum += nums[i];
            osum = max(csum , osum);
            }
            else{
                csum = nums[i];
                osum = max(csum, osum);
            }
        }
        return osum;
    }
};
```
