##### I N T U I T I O N
    In a rotated sorted array, the index of the minimum element equals the number of right rotations.
    Binary search is used to locate this minimum by comparing arr[mid] with the last element—if greater, the minimum lies right; otherwise, it lies left (or at mid).

  ##### C O D E
```cpp
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int start =0;
        int end = arr.size()-1;
        int ans = 0;
        int n = arr.size();
        
        while(start<=end){
            
            int mid = start+((end-start)/2);
            
            if(arr[mid]==1){
                ans = mid;
                break;
            }
            else if(arr[mid]>arr[n-1]){
                start = mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        
        return ans;
        
    }
};

};
```
