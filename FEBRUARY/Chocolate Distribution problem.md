###### C O D E
```cpp
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        sort(a.begin(),a.end());
        int i = 0,j = m-1;
        int mini = 1e9;
     while(j<n){
         
             mini = min(a[j]-a[i],mini);
         
         i++;j++;
     }
     return mini;
    }
};
```
