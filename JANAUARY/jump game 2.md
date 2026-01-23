
                           **I N T U I T I O N**
                          
      We move in ranges, not step by step.
    
    [l … r] = all positions we can reach with the current number of jumps.
    
    From this range, find how far we can reach next (far).
    
    Then move to the next range and increase jump count.
    
    Stop when the range reaches the last index.
     
```cpp
 class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = 0, far = 0;
        int jumps = 0;
        while(r<n-1){

            for(int it = l ; it <= r ; it++){
                far = max(far, it+nums[it]);
            }
            l = r+1;
            r = far;
            jumps++;
        }
        return jumps;
    }
};
```
