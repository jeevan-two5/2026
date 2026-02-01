    
#####  I N T U I T I O N

      First, find the maximum of the first window of size k.
    
    Slide the window one step at a time:
    
    If the new incoming element is bigger than current maxi, update it.
    
    If the outgoing element was the maximum, recompute max for the current window.
    
    Push the maximum for each window into the answer.
    
    👉 This avoids recomputing every time, except when the max leaves the window.


#####  C O D E 

```cpp
  class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int>ans;
        int maxi = arr[0];
        for(int x = 1 ; x < k ; x++){
            maxi = max(maxi,arr[x]);
        }
       ans.push_back(maxi);
        int i = 1 , j = k;
        while(j<n){
            if(arr[j] > maxi){
                maxi = arr[j];
            }
            else if(arr[i-1] == maxi){
                 maxi = arr[i];
                for(int x = i; x <= j ;x++)
                    maxi = max(maxi,arr[x]);
            }
            ans.push_back(maxi);
            i++;
            j++;
        }
        return ans;
    }
};
```
