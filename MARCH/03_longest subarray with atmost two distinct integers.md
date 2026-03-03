
###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/8e7b5363-c3a5-4c3d-bb3c-49c5a28295d1" />

######  I N T U I T I O N
. Intuition (The Sliding Window)

Manam oka "window" (subarray) ni maintain chestham,

andulo maximum 2 different numbers matrame undela chuskovali.

Expanding: Window ni right side ki penchuthu vellali, kotha numbers add chesthu.

Shrinking: Okavela window lo 3rd distinct number vachindante, 

window left side nundi numbers ni remove cheyali... eppati varaku? 

Malli kevalam 2 distinct numbers migile varaku.

Goal: Prathi step lo window length ($right - left + 1$) ni calculate chesi, 

maximum length ni store cheskovali.

###### C O D E

```cpp
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxi = 0;
        unordered_map<int,int>freq;
        int l = 0;
        for(int r = 0; r<n;r++){
            freq[arr[r]]++;
            
            while(freq.size() > 2){
                freq[arr[l]]--;
                if(freq[arr[l]]  == 0){
                    freq.erase(arr[l]);
                }
                l++;
            }
            
            maxi = max(maxi,r-l+1);
        }
        return maxi;
    }
};
```
