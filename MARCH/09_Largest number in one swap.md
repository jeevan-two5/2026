###### I M A G E
<img width="1264" height="843" alt="image" src="https://github.com/user-attachments/assets/5b25410e-7d8e-4a86-97cf-ab68e21bdefb" />

###### I N T U I T I O N
<img width="743" height="531" alt="image" src="https://github.com/user-attachments/assets/da5d06d4-e4ab-4a21-9bf1-e4f898bf8746" />

###### C O D E
```cpp
class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        vector<int>last_pos(10,-1);
        for(int i = 0; i<n;i++){
            last_pos[s[i] - '0'] =i;
        }
        
        for(int i = 0; i<n;i++){
            int curr = s[i] - '0';
            
            for(int dig = 9; dig > curr; dig--){
                if(last_pos[dig] > i) {
                    swap(s[i],s[last_pos[dig]]);
                    return s;
                }
            }
        }
        return s;
    }
};
```
