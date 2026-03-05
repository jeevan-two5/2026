###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/6f3b9f2b-064f-4de8-aa8a-ccaee1788913" />

###### I N T U I T I O N
    Goal: We want a window where all characters can become the same. 
    
    To do this with the fewest changes,
    
    we pick the most frequent character as our "anchor" and 
    
    change everything else.
    
    The Condition: For any window of length $L$, 
    
    the number of characters we need to change is:
    
    $$\text{Changes needed} = \text{Window Length} - \text{Count of Most Frequent Character}$$
    
    The Rule: If $\text{Changes needed} > k$, the window is invalid. 
    
    We must shrink it from the left until it becomes valid again.
    
    Maximization: As we slide the right pointer $r$, we keep track of the largest valid window size we’ve ever seen.

###### C O D E
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char,int>freq;
        int l =0,cnt=0,max_freq =0,maxi = 0;
        for(int r = 0; r<n;r++){
            freq[s[r]]++;
            max_freq = max(max_freq , freq[s[r]]);
                
                while(((r-l+1) - max_freq) > k){
                    freq[s[l]]--;
                    l++;
                }
            maxi = max(maxi,r-l+1);
        }
        return maxi;
        }
        
};
```
