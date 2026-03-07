###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/0449a2bf-14b8-4fc9-abd1-7f091ebc54d8" />

###### I N T U I T I O N
<img width="586" height="331" alt="image" src="https://github.com/user-attachments/assets/b3c1b2d5-81e0-435e-9c6b-b4f808de677d" />

###### C O D E
```cpp
class Solution {
  public:
    string f(string &s1, string &s2){
        string ans = "";
        unordered_map<char,int>map2;

        for(int i = 0;i<s2.length();i++){
                char ch = s2[i];
                map2[ch]++;
        }

        int mct = 0; // match count
        int dmct = s2.length(); //desired match count

        unordered_map<char,int>map1;

        int i = -1, j = -1;
        
        while(true){
            bool f1 = false,f2 = false;

            //s-1
            while(i < (int)s1.length() - 1  &&  mct < dmct){
                i++;
                char ch = s1[i];
                map1[ch]++;
  
                if(map1[ch] <= map2[ch]) mct++;             // kaam ka bandha hua toh
                f1 = true;
            }
            
            //s-2
            while(j < i && mct == dmct){
                string pans = s1.substr(j+1,i-j);             // potential ans 
                if(ans.length() == 0 || pans.length() < ans.length()) ans = pans;

                j++;
                char ch = s1[j];

                if(map1[ch] == 1) map1.erase(ch);
                else map1[ch]--;

                if(map1[ch] < map2[ch]) mct--;             // kaam ka bandha hua toh
                f2 = true;
            }
            
            if(f1 == false && f2 == false) break;
        }
        return ans;
        
    }
    string minWindow(string &s, string &p) {
        // code here
        return f(s,p);      
    }
};
   
```
