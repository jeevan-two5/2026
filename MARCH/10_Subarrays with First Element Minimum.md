###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/1e89faa6-0946-4f91-bb62-7d29d8265872" />

###### I N T U I T I O N
<img width="598" height="481" alt="image" src="https://github.com/user-attachments/assets/614222d6-05b5-48bd-a0db-4ecd10cacc40" />

###### C O D E 
```cpp
class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>nse(n,n);
        stack<int>st;
        for(int i = 0; i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                nse[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i<n;i++){
            ans += (nse[i] - i);
        }
        return ans;
    }
};
```
