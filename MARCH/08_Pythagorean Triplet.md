###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/eca7528b-54ce-4220-9128-d760eb81319f" />

###### I N T U I T I O N
<img width="536" height="654" alt="image" src="https://github.com/user-attachments/assets/ef389e8e-d3fd-4f80-b616-92e70156610d" />

###### C O D E
```cpp
  class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int present[1001]={0};
            int n = arr.size();
        for(int i = 0; i<n;i++){
            present[arr[i]] =1;
        }
        
        for(int i = 1; i<= 1000; i++){
            if(!present[i]) continue;
            for(int j = i+1; j<= 1000; j++){
                if(!present[j]) continue;
                int sum = i*i + j*j;
                int c = sqrt(sum);
                if(sum == c*c && c<= 1000 && present[c]) return true;
            }
        }
        return false;
    }
};
```

