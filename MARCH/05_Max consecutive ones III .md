###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/2ba65a6e-1cd7-4fc5-99ba-118c640aba0c" />

###### I N T U I T I O N

We want to find the longest subarray that contains only 1s.

Since we are allowed to flip at most k zeros, 

our goal is to find the largest "window" that contains no more than k zeros.

Expand: Move the right pointer r to include a new number.

The Constraint: If the number of 0s in your current window $[l, r]$ exceeds k,

the window is "broken."Shrink: Move the left pointer l forward until 

you have tossed out enough zeros to make the window valid again (i.e., zeros $\le k$).

Track: The largest window size you ever managed to maintain is your answer.

###### C O D E 1
```cpp
  class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int l = 0,cnt =0,maxi =0,max_freq =0;
        for(int r = 0; r<n;r++){
            freq[nums[r]]++;
            if(nums[r]==1)max_freq = max(max_freq,freq[nums[r]]);

            while(((r-l+1)-max_freq)>k){
                freq[nums[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);

        }
        return maxi; 
    }
};
```

###### C O D E 2
```cpp
  int longestOnes(vector<int>& nums, int k) {
    int l = 0, r = 0, zeros = 0, maxi = 0;
    
    for (r = 0; r < nums.size(); r++) {
        if (nums[r] == 0) zeros++; // Track zeros directly
        
        while (zeros > k) { // If too many zeros, shrink from left
            if (nums[l] == 0) zeros--;
            l++;
        }
        
        maxi = max(maxi, r - l + 1);
    }
    return maxi;
}
```
