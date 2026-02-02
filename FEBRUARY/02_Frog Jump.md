##### I N T U I T I O N &nbsp; ( M E M O)
    To reach stair i, frog comes from i-1 or i-2
    
    Cost = jump cost + minimum cost to reach previous stair
    
    So dp[i] = min(dp[i-1] + |h[i]-h[i-1]|, dp[i-2] + |h[i]-h[i-2]|)
    
    Use DP (memoization/tabulation) to avoid recomputation.

##### M E M O I S A T I O N    &nbsp;&nbsp;&nbsp;  TC : O(N) &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  SC: O(N) 
```cpp
class Solution {
    
    int f(int index, vector<int>&height,vector<int>&dp){
        if(index == 0) return 0;
        if(dp[index] != -1) return dp[index];
        int jump2 = INT_MAX;
        int jump1 = f(index-1, height,dp) + abs(height[index] - height[index-1] );
        if(index >1)
         jump2 = f(index-2,height,dp)+abs(height[index] -height[index-2]);
        return dp[index] = min(jump1,jump2);
    }
    
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,-1);
        return f(n-1,height,dp);
    }
};
```
