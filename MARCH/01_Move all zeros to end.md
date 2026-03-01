###### attached IMAGE
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/4fc80daf-5d77-4d51-8ba7-15228d932bbf" />

###### I N T U I T I O N
    j pointer eppudu "modati zero" ekkada undo chupisthu untundi. 
    i pointer non-zero element ni vethiki, daanni techi j unna chota patti kurchobeduthundi. 
    Swap avvagaane j++ chestham kabatti, j eppudu next available zero seat daggare untundi.
###### C O D E
```cpp
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        int j = -1;
        for(int i = 0; i<n;i++){
            if(arr[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;
        for(int i = j+1; i<n;i++){
            if(arr[i] != 0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};
```
