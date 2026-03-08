###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/f57a673f-e26e-4f45-ac58-0cbf541654d8" />

###### I N T U I T I O N
<img width="553" height="683" alt="image" src="https://github.com/user-attachments/assets/a68b7909-c42f-4721-810e-eaaf2a6a030b" />

###### C O D E
``` cpp
    class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // i-th string lo unna i-th character ni check cheyi
            // Adi '0' ayithe '1' pettuko, '1' ayithe '0' pettuko
            if (nums[i][i] == '0') {
                ans += '1';
            } else {
                ans += '0';
            }
        }
        
        return ans;
    }
};
```
