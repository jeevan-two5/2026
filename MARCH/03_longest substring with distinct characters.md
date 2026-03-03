###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/a2658c1c-d826-4fc7-ad06-4cab2536d95d" />

###### C O D E

```cpp
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
            int n = s.length();
            int l = 0,maxi = 0;
        unordered_map<char,int>freq;
        for(int r = 0; r<n;r++){
            freq[s[r]]++;
            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
        }
        return maxi;
    }
};

```
