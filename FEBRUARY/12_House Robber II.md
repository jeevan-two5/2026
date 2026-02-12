##### C O D E 

```cpp
  class Solution{
    private: 
    int f(vector<int>&arr){
          // this was the tabulation code of House Robber I 
        int n = arr.size();
        vector<int>dp(n,0);
        dp[0] = arr[0];
        for(int i = 1;  i < n;i++){
            int pick = arr[i];
            if(i>1) pick += dp[i-2];
            int notpick = 0 + dp[i-1];
           dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int i  = 0;
        int n = nums.size();
        if(n==1) return nums[0];
        while(i < n){
        if(i != 0) arr1.push_back(nums[i]);
        if(i != n-1) arr2.push_back(nums[i]);
        i++;
        }
        int ans1 = f(arr1);
        int ans2 = f(arr2);
        return max(ans1,ans2);
    }
};
```
