#Intuition

Intuition (very simple & short):

Every child must get at least 1 candy → start with all 1s.

Left to right: if current rating is higher than previous, give more candy than left neighbor.

Right to left: if current rating is higher than next, make sure it has more candy than right neighbor.

Use max so earlier correct values are not broken.

Finally, add all candies → that is the minimum needed. 

``` cpp
class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>c(n,1); // c- candy
        //int 
        for(int i = 1; i<n;i++){
            if(arr[i] > arr[i-1]){
                c[i] = 1 + c[i-1];
            }
        }
        int total = c[n-1];
        for(int i = n-1; i >= 1; i--){
            if(arr[i] < arr[i-1] ){
                c[i-1] = max(c[i-1] , 1+c[i] );
            }
                total += c[i-1];
        }
        return total;
    }
};

```
