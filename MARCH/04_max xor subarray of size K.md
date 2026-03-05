###### I M A G E 

<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/d5ae8072-8ab4-4198-9292-037dd728c009" />

###### I N T U I T I O N
    1️⃣ First Window
    Compute XOR of first k elements.
    
    xorr ^= arr[i];
    
    This gives XOR of first subarray.
    
    2️⃣ Slide the Window
    
    For next window:
    
    Add new element → xorr ^= arr[i]
    
    Remove old element → xorr ^= arr[i-k]
    
    Why works?
    Because:
    
    A ^ A = 0
    
    So removing an element is just XORing it again.
    
    3️⃣ Update Answer
    
    After each window:
    
    ans = max(ans, xorr);
    Maintain a sliding window of size k, update XOR by 
    adding new element and removing old element using XOR property.
    
###### C O D E 
```cpp
  class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0; 
        int xorr = 0; 
        for(int i = 0; i<k-1;i++){
            xorr ^=arr[i];
        }
        for(int i = k-1;i<n;i++){
            xorr ^=arr[i];
            ans = max(ans,xorr);
            xorr^= arr[i-k+1];
        }
        return ans;
    }
    
};
```
