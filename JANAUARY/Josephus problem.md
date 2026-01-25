####          I N T U I T I O N
    We build the answer gradually from 1 person to n people.
    
    For 1 person, the survivor is obviously position 1.
    
    But internally, to make shifting easy, we temporarily think in 0-based while calculating.
    
    At each step i (number of people):
    
    The previous safe position shifts by k because every k-th person is eliminated.
    
    So we update:
    
    ans = (ans + k) % i
    
    
    % i keeps the position inside the current circle of i people.

```cpp
class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = (ans+k)%i;
        }
        return ans+1;
    }
};
```
