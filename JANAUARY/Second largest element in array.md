```cpp
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int L = -1; 
        int SL =  -1;
        for(int i = 0; i<n;i++){
            if(arr[i] > L){
                SL = L;
                L = arr[i];
            }
            else if(arr[i] < L && SL < arr[i]){
                SL = arr[i];
            }
        }
        return SL;
    }
};
```
