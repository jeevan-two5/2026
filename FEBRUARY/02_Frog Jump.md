##### I N T U I T I O N &nbsp; ( M E M O)
    To reach stair i, frog comes from i-1 or i-2
    
    Cost = jump cost + minimum cost to reach previous stair
    
    So dp[i] = min(dp[i-1] + |h[i]-h[i-1]|, dp[i-2] + |h[i]-h[i-2]|)
    
    Use DP (memoization/tabulation) to avoid recomputation.

##### M E M O I S A T I O N    &nbsp; &nbsp; &nbsp;  TC : O(N) &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  SC: O(N) 
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

#####  T A B U L A T I O N 
    Tabulation (Bottom-Up DP)
    
    Intuition:
    
    Build solution from 0 → n−1
    
    At each stair, take the minimum of coming from 1 step or 2 steps back
    
    Time Complexity: O(n)
    Space Complexity: O(n) (DP array)

  ```cpp
    // Tabulation (Bottom-Up DP)
int minCost(vector<int>& height) {
    int n = height.size();
    vector<int> dp(n, 0);

    dp[0] = 0;

    for (int ind = 1; ind < n; ind++) {
        int jump1 = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
        int jump2 = INT_MAX;
        if (ind > 1)
            jump2 = dp[ind - 2] + abs(height[ind] - height[ind - 2]);

        dp[ind] = min(jump1, jump2);
    }

    return dp[n - 1];
}

```

##### S P A C E  &nbsp; &nbsp;&nbsp;&nbsp; O P T I M I S A T I O N

    Intuition:
    
    Only the previous two states are needed at any time
    
    Replace DP array with two variables
    
    Time Complexity: O(n)
    Space Complexity: O(1)

```cpp
// Space Optimized DP
int minCost(vector<int>& height) {
    int n = height.size();

    int prev1 = 0;  // dp[i-1]
    int prev2 = 0;  // dp[i-2]
    int curr = 0;

    for (int ind = 1; ind < n; ind++) {
        int jump1 = prev1 + abs(height[ind] - height[ind - 1]);
        int jump2 = INT_MAX;
        if (ind > 1)
            jump2 = prev2 + abs(height[ind] - height[ind - 2]);

        curr = min(jump1, jump2);

        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

```
  
