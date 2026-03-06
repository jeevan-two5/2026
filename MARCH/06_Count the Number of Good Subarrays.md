###### I M A G E 
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/e755fe71-2853-40ef-b7b1-d2631e4a768b" />

###### I N T U I T I O N
<img width="602" height="414" alt="image" src="https://github.com/user-attachments/assets/658fb06a-7123-4784-87e0-971093b9cebd" />

    ### Logic: Sliding Window + Pair Combinatorics
    - Use a frequency map to track pairs: `cnt += freq[nums[r]] - 1`.
    - When `cnt >= k`, all subarrays from current `r` to the end of the array are valid.
    - Shrink from the left to find the next smallest valid window.

###### C O D E
```cpp
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int  l = 0;
        long long cnt = 0,ans = 0;
        for(int r= 0; r<n;r++){
            freq[nums[r]]++;
            cnt += (freq[nums[r]] - 1);
            while(cnt >= k){
                ans += (n-r);
                cnt -= (freq[nums[l]] - 1);
                freq[nums[l]]--;
                l++;
            }
        }
        return ans;
    }
};
```
