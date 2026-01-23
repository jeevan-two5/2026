    I N T U I T I O N
    This is the stock span problem.
    
    For each day i, we want to know how many previous days had price ≤ today’s price.
    
    The stack stores indices of days with higher prices (it removes smaller ones).
    
    When the stack becomes empty, today’s price is highest so far → span = i + 1.
    
    Otherwise, the top of stack blocks us → span = distance from that day.
```cpp
class Solution {
  public:
  //traversing left
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
       vector<int>res(n);
       stack<int>st;
       for(int i = 0; i< n;i++){
           while(!st.empty() && arr[st.top()] <=arr[i]){
               st.pop();
           }
           
           res[i] = st.empty() ? (i + 1) : i - st.top();
           st.push(i);
       }
       return res;
    }
};                                                                                                              

```
