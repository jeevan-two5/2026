<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/8e46593c-f764-4b1d-9725-c500f064589a" />
###### C O D E 
```cpp
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        
        // We go up to index 1 because the last remaining '1' (at index 0)
        // doesn't need more operations once we reach it.
        for (int i = s.size() - 1; i > 0; i--) {
            int digit = (s[i] - '0') + carry;
            
            if (digit == 1) {
                // Odd number: Add 1 (1 step) and it becomes even, 
                // then divide by 2 (1 step). Total 2 steps.
                steps += 2;
                carry = 1; 
            } else {
                // Even number (either 0+0 or 1+1): 
                // Just divide by 2 (1 step).
                steps += 1;
                // If digit was 2 (1+1), carry remains 1. 
                // If digit was 0 (0+0), carry remains 0.
            }
        }
        
        return steps + carry;
    }
};
```
