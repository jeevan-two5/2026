###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/0449a2bf-14b8-4fc9-abd1-7f091ebc54d8" />

###### I N T U I T I O N
<img width="586" height="331" alt="image" src="https://github.com/user-attachments/assets/b3c1b2d5-81e0-435e-9c6b-b4f808de677d" />

###### C O D E
```cpp
class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n = s.size();
        int freq[256] {0};
        for(int i = 0; i<p.size();i++){
            freq[p[i]]++;
        }
        int l = 0,cnt = 0;
        int minlen = INT_MAX;
        int startIndex = -1;
        for(int r = 0 ;   r<n;r++){
            
            if(freq[s[r]] > 0) cnt++;
            freq[s[r]]--;
            while(cnt == p.size()){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    startIndex = l;
                }
                freq[s[l]]++; 
                if(freq[s[l]] > 0) cnt--;
                l++;
            }
        }
        return startIndex==-1 ? "":s.substr(startIndex,minlen);
    }
    
};
   
```
