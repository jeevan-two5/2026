##### I N T U I T I O N

    The Correct Approach (Sweep Line Algorithm)
    
    To solve this, you should separate the start times and end times, sort them individually, and "sweep" through time.
    
    1. Separate Starts and Ends: Create two arrays: starts and ends
    
    2. Sort Both: Sort both arrays in ascending order.
    
    3. Two-Pointer Sweep:
    
    If a start time is an end time, it means a new interval has begun before an old one finished. Increment your current count.
    
    If a start time is > an end time, an interval has finished. Decrement your current count.
    
    Keep track of the max count seen during this process.
###### C O D E
```cpp
class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        vector<int>start,ends;
        for(auto& c: arr){
            start.push_back(c[0]);
            ends.push_back(c[1]);
        }
            sort(start.begin(),start.end());
            sort(ends.begin(),ends.end());
            int cnt =0 ,maxi = 0;
            int i = 0,j=0;
            while(i<n && j<n){
                if(start[i]<=ends[j]){
                    cnt++;
                    maxi = max(maxi,cnt);
                    i++;
                }
                else{
                    cnt--;
                    j++;
                }
            }
            return maxi;
    }
};


```
