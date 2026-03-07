###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/19b93404-24af-4892-bf4b-169b5dc4d345" />

###### I N T U I T I O N
<img width="568" height="576" alt="image" src="https://github.com/user-attachments/assets/441f4429-c588-4a5d-b493-a4b2cc384b88" />

###### C O D E
```cpp
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string l = s;
        for(auto& c: s){
            l.push_back(c);
        }
        string p1,p2;
        int i = 0;
        while(i<l.size()){
            if(i%2 == 1){ 
                p1.push_back('0');
                p2.push_back('1');
            }
            else {
                p1.push_back('1');
                p2.push_back('0');
            }
            i++;
        }
         int mini = INT_MAX;
        int diff1 = 0,diff2 = 0;
        for(int i = 0; i<l.length();i++){
            
            if(p1[i] != l[i]) diff1++;
            if(p2[i] != l[i]) diff2++;
            if(i >= n){
                if(p1[i-n] != l[i-n]) diff1--;
                if(p2[i-n] != l[i-n]) diff2--;
            }
            if(i >= n-1){
                mini = min({diff1,diff2,mini});
            }
        }

      return mini;
    }
};
```
###### C O D E &nbsp;&nbsp; Q U A L I T Y
```cpp
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string s2 = s + s; // Type-1 operations handle cheyadaniki
        
        // Rendue possibilities: 0101... leda 1010...
        string p1 = "", p2 = "";
        for(int i = 0; i < s2.length(); i++) {
            p1 += (i % 2 == 0 ? '0' : '1');
            p2 += (i % 2 == 0 ? '1' : '0');
        }
        
        int ans = INT_MAX;
        int diff1 = 0, diff2 = 0;
        
        for(int i = 0; i < s2.length(); i++) {
            // Window loki element add chestunnam
            if(s2[i] != p1[i]) diff1++;
            if(s2[i] != p2[i]) diff2++;
            
            // Window size n datithe, left side nundi remove cheyali
            if(i >= n) {
                if(s2[i - n] != p1[i - n]) diff1--;
                if(s2[i - n] != p2[i - n]) diff2--;
            }
            
            // Window size exact ga n unnapudu minimum check cheyali
            if(i >= n - 1) {
                ans = min({ans, diff1, diff2});
            }
        }
        
        return ans;
    }
};
```
