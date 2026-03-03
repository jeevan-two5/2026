###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/b7fbaefd-d9e2-4e28-9195-8c75f602aedd" />

###### I N T U I T I O N
    Define atMost(K): This function counts all subarrays
    
    where the number of distinct integers is less than or equal to $K$.
    
    Sliding Window Mechanism:
    
    Use a Frequency Map to track distinct elements.Expand the right pointer to include new elements.
    
    If map.size() > K, shrink the window by moving the left pointer until the size is back to $K$.
    
    Counting Subarrays:For every valid window [left, right], 
    
    the number of new subarrays ending at right is: right - left + 1.
    
    Accumulate this value to get the total count for atMost(K).
    
    Final Calculation:
    
    Calculate atMost(nums, K).
    
    Calculate atMost(nums, K - 1).
    
    The difference gives the subarrays with exactly $K$ distinct integers.

###### C O D E

```cpp
class Solution {
  public:
  int f(vector<int>&nums,int k){
      int l = 0,cnt = 0;
      unordered_map<int,int>freq;
      for(int r = 0; r<nums.size() ; r++){
          freq[nums[r ]]++;
          while(freq.size() > k){
              freq[nums[l]]--;
              if(freq[nums[l]] == 0) freq.erase(nums[l]);
              l++;
          }
          cnt += (r-l+1);
      }
      return cnt;
  }
    int exactlyK(vector<int> &arr, int k) {
        // code here
        return f(arr,k) - f(arr,k-1);
    }
};
```
