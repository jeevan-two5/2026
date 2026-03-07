###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/210273e1-b02a-4aaf-b3ed-f13919ab3d9a" />

###### I N T U I T I O N
<img width="606" height="450" alt="image" src="https://github.com/user-attachments/assets/2142205b-bcf2-4ecc-bc74-d0b263e4f343" />

###### C O D E
```cpp
class Solution {
  public:
    int minFlips(string& s) {
        // code here
        string p1,p2;
        int i = 0; 
        int n = s.length();
        while(i<n){
            p1 += (i%2 == 0 ? '0':'1');
            p2 += (i%2 == 0 ? '1' :'0');
            i++;
        }
        int    cnt1 = 0,cnt2 =0;
        for(int i = 0; i<n;i++ ){
            if(s[i] != p1[i]) cnt1++;
            if(s[i] != p2[i]) cnt2++;
        }
        return min(cnt1,cnt2);
    }
};

```
