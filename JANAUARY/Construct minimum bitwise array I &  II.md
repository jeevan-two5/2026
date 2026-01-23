#### I N T U I T I O N
    For each number nums[i], we want to find a number x such that
    x OR (x + 1) = nums[i].
    
    We try all possible x from 0 to nums[i] - 1.
    
    For each x, we check if OR-ing it with the next number gives the target.
    
    The first valid x is the smallest, so it’s optimal.
    
    If no such x exists, we return -1 for that number.
    
    Do this independently for every element in nums.
    
 #### BRUTE
  ``` cpp
//=========================     B R U T E      =============
  class Solution {
  public:
      vector<int> minBitwiseArray(vector<int>& nums) {
          int n = nums.size();
          vector<int>ans;
          for(int i = 0; i< n; i++){
              bool found = false;
              for(int x = 0; x < nums[i] ;x++){
                  if((x|(x+1)) == nums[i] ) {
                      found = true;
                      ans.push_back(x);
                      break;
                  }
              }
              if(!found ) ans.push_back(-1);
          }
          return ans;
      }
  };
  ```

#### O P T I M A L ____ I N T U I T I O N
    We want a number x such that
    x | (x + 1) = nums[i], and x should be minimum.
    
    In binary, this happens when:
    
    We flip the rightmost 1 bit of nums[i] to 0
    
    All lower bits stay 1, so (x + 1) fills them back.
    
    We scan bits from LSB to MSB to find the first 0 bit.
    
    Just before that 0, there is a 1 → that is the bit we flip.
    
    Using XOR, we turn that 1 into 0 to get the smallest x.
    
    If this is not possible (like for 2 → 10), return -1.
    
    👉 This avoids brute force and directly builds the answer using bit behavior.

    
#### OPTIMAL
```cpp
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            if(nums[i] == 2) {
                ans.push_back(-1);
                continue;
            }
            bool found = false;
            for(int j = 0; j < 32; j++){
                if((nums[i] & (1<<j ) ) != 0 ) { // set back (to find the first zero from last)
                    continue;
                }
                int prev = j-1;
                ans.push_back( nums[i] ^ (1<<(j-1))); //XOR
                found = true;
                break;
            }
            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};
```
