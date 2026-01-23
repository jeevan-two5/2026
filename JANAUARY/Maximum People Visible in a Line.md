         I N T U I T I O N
    Think of each person’s height in arr.

    For every index i, we want to know how many people he can “see” to the left and right until someone taller or equal blocks the view.
    
    res1[i]: number of people visible on the left (using a stack to stop at a taller person).
    
    res2[i]: number of people visible on the right (same idea, but from right to left).
    
    Add both sides and subtract 1 (because person i is counted twice).
    
    Take the maximum of this value → that’s the answer.

```cpp
class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
      int n = arr.size();
      vector<int>res1(n);
      stack<int>st1;
      for(int i = 0; i<n; i++){
          while(!st1.empty() && arr[st1.top()] < arr[i]){
              st1.pop();
          }
          res1[i] = st1.empty() ? i+1 : i - st1.top();
          st1.push(i);
      }
      vector<int>res2(n);
      stack<int>st2;
      for(int i = n-1; i>=0;i--){
          while(!st2.empty() && arr[st2.top()] < arr[i]){
              st2.pop();
          }
          res2[i] = st2.empty() ? (n-i) : st2.top() - i;
          st2.push(i);
      }
      vector<int>ans(n);
      int maxi = 0;
      for(int i = 0; i<n;i++){
          ans[i] = res1[i]+res2[i] - 1;
          maxi = max(maxi,ans[i]);
      }
      return maxi;
      
    }
};
```
