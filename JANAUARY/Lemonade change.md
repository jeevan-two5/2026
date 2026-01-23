## I N T U I T I O N ##
    Each customer pays with 5, 10, or 20.
    
    We must always give correct change using money we already have.
    
    Keep count of ₹5, ₹10, ₹20 notes.
    
    ₹10 needs one ₹5 as change.
    
    ₹20 needs ₹10 + ₹5 first (best), otherwise three ₹5.
    
    If change is not possible at any step → return false.
    
    If all customers are handled → return true.

  ```cpp

    class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n = arr.size();
        int fives = 0, tens=0,twentys = 0;
        for(int i = 0 ; i< n; i++){
            if(arr[i] == 5) fives++;
            else if(arr[i] == 10){
                tens++;
                if(fives) fives--;
                else return false;
            }
            else{
                twentys++;
                if(tens && fives) {
                    tens--;
                    fives--;
                }
                else if(fives >= 3 && tens ==0){
                    fives = fives -3;
                }
                else{
                    return false;
                }
            }  
        }
        return true;
    }
};
```
