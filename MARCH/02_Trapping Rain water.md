###### I N T U I T I O N
      Prati block daggara entha water trap avthundhi annadhi, 
      aa block ki left side unna tallest building and 
      right side unna tallest building decide chesthayi.
      
      Water Level: Oka particular position i daggara water level entha undali ante,
      left lo unna maximum height (left[i]) and right lo unna
      maximum height (right[i]) lo edi thakkuvaga (minimum) unte anthe water level untundhi.
      
      Trapped Water: Aa water level nundi mana
      current block height (arr[i]) ni minus chesthe, 
      aa gap lo entha water aaguthundho telusthundhi.
      
      Formula: Trapped_Water = min(Left_Max, Right_Max) - Current_Height
      

###### C O D E
```cpp
  class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();t
        int res = 0;
        vector<int>left(n);
        left[0] = arr[0];
        for(int i = 1; i<n;i++)
            left[i] = max(arr[i],left[i-1]) ;
            
        vector<int>right(n);
        right[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--)
            right[i] = max(right[i+1] , arr[i]);
        
        for(int i = 1; i<n-1;i++){
           int minof2 = min(left[i],right[i]);
            res += (minof2-arr[i]);
        }
        return res;
    }
};
```
