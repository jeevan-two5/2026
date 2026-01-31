  #### I N T U I T I O N
        One big array arr[] stores elements of all k queues.
        
        next[] works like links: it connects queue elements and maintains a free list.
        
        front[] and rear[] store start/end index of each queue.
        
        freespot points to the first free index in arr[].
        
        Enqueue: take index from freespot, link it to queue i, update freespot.
        Dequeue: remove from front[i], put that index back into free list.
        
        👉 Efficiently implements k queues in O(1) using a single array.
#### CODE
```cpp
class kQueues {
    int n, k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        this->n = n;
        this->k = k;
        
        next = new int[n];
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        
        for(int i = 0; i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        for(int i = 0;  i < n-1;i++ ) next[i] = i+1;
        next[n-1] = -1;
        freespot = 0;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if(isFull()) return;
        int index = freespot;
        freespot = next[index]; 
        if(front[i] == -1)  front[i] = index;
        else next[rear[i]] = index;
    
        next[index] = -1; 
        rear[i] = index;
        arr[index] = x;
    
}


    int dequeue(int i) {
        // dequeue element from queue i 
        if(isEmpty(i)) return -1;
        int index = front[i];
        front[i] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return front[i] == -1;
    }

    bool isFull() {
        // check if array is full
        return freespot == -1;
    }
};

```
