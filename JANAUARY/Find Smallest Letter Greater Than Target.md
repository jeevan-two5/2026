##### C O D E 
```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char c : letters){
            if(target - '0' < c - '0'){
                return c;
            } 
        }
        return letters[0];
    }
};
        

```
