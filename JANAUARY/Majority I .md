```cpp
class Solution {
  private:
    bool g(vector<int>&nums,int val){
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            if(nums[i] ==val) cnt++;
        }
        return cnt > n/2;
    }
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int val1 = arr[0];
        int cnt1 = 1; 
        int i =1;
        while(i<n){
        if(val1 == arr[i]){
            cnt1++;
            
        }
        else {
            if(cnt1==0){
                val1 = arr[i];
            }
            else cnt1--;
                
            }
            i++;
        }
        if(g(arr,val1) == true) return val1;
        return -1;
    }
};
```
