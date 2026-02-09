```cpp
  class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
       // int val = arr[0];
       int k = 1;
        for(int i = 1 ; i< arr.size();i++){
            if(arr[i]  > arr[i-1]) k++;
            else return k;
        }
    }
};
```
