###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/42e16138-4036-485b-bd00-d5ebcbd5e595" />

###### I N T U I T I O N
    The Window: We use two pointers, l (left) and r (right), to represent a subarray. 
    
    As we move r to the right, we multiply the current product (cprod) by the new element.
    
    The Constraint: If the product becomes $\ge k$,
    
    we shrink the window from the left by moving l forward and 
    
    dividing the product by nums[l] until it is valid again.
    
    The "Magic" Counting Step: For every valid window ending at r,
    
    the number of new subarrays added is exactly the length of that window: $(r - l + 1)$.

###### C O D E
```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;
        int l = 0, ans = 0,cprod = 1;
        for(int r = 0; r<n;r++){
            cprod *= nums[r];

            while(cprod >= k && l <= r){
                cprod /= nums[l];
                l++;
            }
            ans += (r-l+1);
        }
        return ans;
    }
};
```
