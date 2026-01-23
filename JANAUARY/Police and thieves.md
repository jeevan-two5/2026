###   I N T U I T I O N ##
    First, store positions of police (P) and thieves (T) separately.
    
    A police can catch a thief only if their distance ≤ k.
    
    Use two pointers to try matching the nearest police with nearest thief.
    
    If they are close enough → count a catch and move both.
    
    If too far, move the one that is behind to try a closer match.
    
    This greedy matching gives the maximum catches.
```cpp
class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
            int n = arr.size();
            vector<int>p;
            vector<int>t;
        for(int i = 0; i< n;i++){
            if(arr[i] == 'P') p.push_back(i);
            else t.push_back(i);
        }
        int ans = 0;
        int i = 0,j = 0;
        while(i < p.size() && j < t.size()){
           if(abs(p[i] - t[j]) <= k){ 
                i++;
                j++;
                ans++;
            }
            else if(p[i] < t[j]) i++;
            else j++;
        }
        return ans;
    }
};
```
