#### I N T U I T I O N
    Use a map to count how many times each character appears.
    
    Use a queue to keep characters in the order they come.
    
    For each character:
    
    Increase its count and push it into the queue.
    
    Remove characters from the front of the queue if their count becomes more than 1.
    
    The front of the queue is the first non-repeating character.
    
    If the queue is empty, add # to the answer.
    
#### C O D E
```cpp
class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
     unordered_map<char, int>freq;
     queue<char>q;
     string ans = "";
     for(char ch : s) {
         freq[ch]++;
         q.push(ch);
         while(!q.empty() && freq[q.front()] > 1 ){
             q.pop();
         }
         if(q.empty())  ans += '#';
                       
         else    ans += q.front();
     }
     return ans;
    }
};
```
