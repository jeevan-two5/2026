###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/a558b6dd-d607-41b7-98ca-02fb46ee5fef" />

######  C O D E
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0,sum = 0;
        int mini = INT_MAX;
        for(int r = 0; r<n;r++){
           sum += nums[r];
      
        while(sum >= target){
            mini = min(r-l+1,mini);
            sum = sum - nums[l];
            l++;
        }
        }
        return (mini == INT_MAX) ? 0 : mini;
    }
};
```
