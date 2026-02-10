#####  I N T U I T I O N
    Subarray Exploration: We use a double loop. The outer loop i sets the 
    start of the window, and the inner loop j expands it.
    
    Tracking Distinctness: As we move j, we keep adding numbers to
    two unordered_set containers. Sets automatically handle "distinctness"
    because they don't store duplicates.
    
    The Balance Check: Every time we add a number,
    we check if distinctEvens.size() == distinctOdds.size().
    If they are equal, the current subarray from i to j is "balanced."
    
    Result: We keep track of the largest window size we've seen so far and return it at the end.

##### C O D E
```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        // Check every possible starting point of a subarray
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinctEvens;
            unordered_set<int> distinctOdds;

            // Expand the subarray from 'i' to the end of the array
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    distinctEvens.insert(nums[j]);
                } else {
                    distinctOdds.insert(nums[j]);
                }

                // If the counts of distinct numbers match, update our max length
                if (distinctEvens.size() == distinctOdds.size()) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }
};
```
