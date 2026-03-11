#####  I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/4277e49e-4696-4129-9e2d-27067cb55ea4" />


##### I N T U I T I O N
<img width="766" height="441" alt="image" src="https://github.com/user-attachments/assets/0dffc66b-3919-495f-98b1-b6e15c11afd9" />

##### C O D E
```cpp
  class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int temp = n;
        int mask = 0;

        // Step 1: n lo enni bits unnayo anni 1s unna mask create cheyali
        while (temp != 0) {
            // Left shift chesi okka bit add chestunnam
            mask = (mask << 1) | 1;
            temp = temp >> 1;
        }

        // Step 2: XOR operation to flip the bits
        return n ^ mask;
    }
};
```
