###### I M A G E

<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/15603bcf-9b33-47bd-8f3b-9b3e86768026" />

###### I N T U I T I O N
      💡 Approach (How we reach goal)
      1️⃣ First Check
      
      Count total distinct characters in whole string.
      If total < k → ❌ impossible → return -1.
      
      2️⃣ Use Sliding Window (Two Pointers)
      
      l = left pointer
      
      r = right pointer
      
      freq map stores character frequencies in current window
      
      3️⃣ Expand Window
      
      Move r forward and add characters to freq.
      
      4️⃣ Shrink When Needed
      
      If distinct characters > k:
      Move l forward and remove characters until distinct = k.
      
      5️⃣ Update Answer
      
      Whenever window has exactly k distinct characters,
      update:
      
      ans = max(ans, window_length)
###### C O D E
```cpp
class Solution {
    
  public:
  int f(string &s, int k){
      int n = s.length();
          int l =0, cnt =0;
          int ans = 0;
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq;
        for(auto &c: s){
            freq1[c]++;
        }
        if(freq1.size() >= k) {
        
        for(int r = 0; r< n;r++){
            freq[s[r]]++;
            while(freq.size()>k){
                freq[s[l]]--;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
            ans = max(ans,r-l+1);
        }
            
        }
        else return -1;
        return ans;
  }
  
    int longestKSubstr(string &s, int k) {
        // code her
        return f(s,k);
    }
};
```
