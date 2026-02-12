##### M E M O I S A T I O N
```cpp
   int MEMO(int ind , vector<int>&arr,  vector<int>&dp){
        if(ind == 0) return arr[ind];
        if(ind < 0 ) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = arr[ind] + f(ind-2,arr,dp);
        int nonpick = 0+ f(ind-1,arr,dp);
        return dp[ind] = max(pick,nonpick);
     }
    int f(vector<int>&nums){
      int n = nums.size();
      vector<int>dp(n,-1);
      return MEMO(n-1,nums,dp);
    }
```
##### T A B U L A T I O N
```cpp
int TABU(vector<int>&arr){
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

```
###### S P A C E &nbsp; O P T I M A T  I O N
