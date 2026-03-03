###### IMAGE
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/01032940-6c02-47fc-96fc-88d19d89c3c4" />

###### I N T U I T I O N
    The findKthBit function determines the value of the bit at position $k$ 
    
    by checking these three sections:Base Case: If $n=1$, the string is always "0", 
    
    so it returns '0'.The Middle Point: The middle index (mid) is calculated as $(length / 2) + 1$.
    
    If $k$ is exactly at this position, the bit is always '1' by definition.
    
    The Left Side ($k < mid$): If $k$ is in the first half, it is identical to the $k^{th}$ bit in $S_{n-1}$.
    
    The function simply moves down to $n-1$ while keeping the same $k$.
    
    The Right Side ($k > mid$): If $k$ is in the second half,
    
    the bit is derived from $S_{n-1}$ but has been inverted and reversed.
    
    To handle the reversal, the code finds the corresponding position
    
    in the original $S_{n-1}$ using the formula len - k + 1.To handle the inversion, 
    
    the code finds the bit at that mirrored position and flips it (if it's '0', it becomes '1', and vice-versa).

###### C O D E 
```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1)  return '0';
        int len = (1<<n) - 1;
        int mid = len/2+1;
        if(k == mid) return '1';

        else if(k<mid) return findKthBit(n-1,k);
        else{
            char bit = findKthBit(n-1,len-k+1);
            return (bit == '0') ?'1': '0';
        }

    }
};
```
