###### C O D E

```cpp
class Solution {
    static bool comp(vector<int>&val1,vector<int>&val2){
        return val1[1]<val2[1];
    }
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(),arr.end(),comp);
        int n = arr.size();
        if(n == 0 || n == 1) return true;
        int endtime = arr[0][1];
        for(int i = 1; i< n;i++){
            if(endtime <= arr[i][0]){
                endtime = arr[i][1];
            }
            else return false;
        }
        return true;
        
    }
};
```
