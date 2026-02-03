  ##### I N T U I T I O N
    Keep track of the minimum price so far (best day to buy).
    
    For each day, compute profit = current price − min price.
    
    Update the maximum profit seen.
    
    Update min price if a lower price appears.
    
    👉 One pass, always buy before sell.
Time: O(n) Space: O(1)
##### CODE   &nbsp;&nbsp;&nbsp;&nbsp; TC : O(N) &nbsp;&nbsp;&nbsp;&nbsp; SC : O(1) 
```CPP
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
     int mini = prices[0];
     int maxi = 0;
     for(int i = 1; i < prices.size() ; i++){
         maxi = max(maxi, prices[i] - mini);
         mini = min (prices[i],mini);
     }
        return maxi;
    }
};
```
