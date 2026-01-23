```cpp


class Solution {
        bool f(vector<int>arr, int val){
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i<n; i++)
            if(arr[i] == val) cnt++;
        return cnt > n/3;
    }
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
         int n = arr.size();
        int cnt1 = 1;
        int cnt2 = 0; 
        int val1 = arr[0];
        int val2 = 1;
        vector<int>ans;
        for(int i = 1; i<n;i++){
            if(val1 == arr[i]) cnt1++;
            else if(val2 == arr[i]) cnt2++;
            else{
                if(cnt1== 0){
                    cnt1 = 1;
                    val1 =arr[i];
                }
                else if(cnt2 == 0){
                    cnt2 = 1; 
                    val2 = arr[i];
                }
                else{
                    cnt1--;
                    cnt2--;
                }
            }
        }
        if(f(arr,val1) == true ) ans.push_back(val1);
        if(val1 != val2 && f(arr,val2) == true) ans.push_back(val2);
       // sort(ans.begin(),ans.end());
        return ans;
    }
};
```
