###### I N T U I T I O N
    Since both arrays are sorted, the smallest value in arr1 is at the start and the largest value in arr2 is at the end.
    
    Start with these two to control the sum efficiently.
    
    If the sum is too large, move left in arr2 to reduce it.
    
    If the sum is too small, move right in arr1 to increase it.
    
    Keep updating the minimum absolute difference — this guarantees we find the closest pair in O(n + m) time.
###### CODE
```cpp
class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
         int n = arr1.size();
    int m = arr2.size();
    int ans1 = 0 , ans2 = 0;
    int min_diff = INT_MAX;
    int i  = 0,j = m-1;
    while(i<n && j >= 0){
     int sum = arr1[i]+arr2[j];
    int  diff = abs(sum - x);
     if(diff < min_diff) {
      min_diff = diff;
      ans1 = arr1[i];
      ans2 = arr2[j];
     }
     else if (sum > x) j--;
     else i++;
    }
   vector<int>ans;
   ans.push_back(ans1);
   ans.push_back(ans2);
  return ans;
    }
};
```
