  ## I N T U I T I O N
    We want the smallest possible number after removing k digits.
    
    If a bigger digit comes before a smaller one, remove the bigger digit.
    
    Use st like a stack to keep digits in increasing order.
    
    Remove digits while it helps make the number smaller and k > 0.
    
    If removals are still left, delete from the end.
    
    Finally, remove leading zeros and return the result.
```cpp
class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        int n = s.size();
        string st; 
        for(int i = 0; i<n;i++){
            while(!st.empty() && k > 0 &&  st.back() > s[i]){
                st.pop_back();
                k--;
            }
            st.push_back(s[i]);
        }
        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }
      int i = 0; 
      while(i < st.size()&& st[i] == '0') i++;
        string res = st.substr(i);
        return res.empty() ? "0" : res;
    }
};
```
