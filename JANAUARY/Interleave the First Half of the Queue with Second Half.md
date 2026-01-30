#### I N T U I T I O N  (OPTIMAL)
    Store first half of queue separately
    
    Remaining elements stay as second half
    
    Push one from first half, then one from second half alternately

#### C O D E  ( OPTIMAL)
```cpp 
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        queue<int> firstHalf;

        // Step 1: move first half into another queue
        for(int i = 0; i < n/2; i++) {
            firstHalf.push(q.front());
            q.pop();
        }

        // Step 2: interleave first half and second half
        while(!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
    }
};

```
####  I N T U I T I O N (OWN)
    First, take all elements out of the queue into an array so we can access them by index.
    
    Split the array into two halves: first half and second half.
    
    Merge them back by taking one element from first half, then one from second half.
    
    Push this rearranged order back into the queue.
    
    👉 Result: queue becomes interleaved (first half + second half alternately).
    
#### C O D E (OWN)
```cpp
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        vector<int>temp(n);
        int j = 0; 
        while(!q.empty()){
            temp[j++] = q.front();
            q.pop();
        }
        vector<int>temp1(n/2);
        vector<int>temp2(n/2);
        
        for(int i = 0; i<n ;i++){
            if(i<n/2) temp1[i] = temp[i];
            else temp2[abs(i-n/2)] = temp[i];
        }
        
        int k = 0 ,i1 =0,i2=0;
        while( k<n && i1<n/2 && i2 < n/2){
            temp[k] = temp1[i1];
            k++;i1++;
            temp[k] = temp2[i2];
            k++;i2++;
        }
        
        for(int i  = 0; i<n;i++){
            q.push(temp[i]);
        }

    }
};
```
