    Intuition (very basic & short):
    
    Think of the last index as the target (goal).
    
    Move from right to left.
    
    If from index i you can reach the current goal, then make i the new goal.
    
    In the end, if the goal becomes 0, it means we can reach the last index from start.
    
    Otherwise, it’s not possible.


```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
       int  goal = n-1;
        for(int i = n -2; i >=0 ; i--){
            if(i+nums[i] >= goal){
                goal = i;
            }
        }
       if(goal == 0) return true;
    return false;
    }
};
```

