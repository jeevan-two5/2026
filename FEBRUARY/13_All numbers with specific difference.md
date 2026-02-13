##### I N T U I T I O N


    The core intuition behind this code is recognizing a mathematical pattern: as a number x increases,
    the difference between the number and its sum of digits (x−sumOfDigits(x)) also increases (it is monotonic).
    
    
    The Goal
    Find how many numbers x in the range [1,n] satisfy:
    
    (x−sumOfDigits(x))≥d
    
    The Approach
    
    Instead of checking every number (which is too slow for n=10^9), 
    we use Binary Search to find the "tipping point."
    
    Monotonicity: If a number x satisfies the condition, then every number greater than x will also satisfy it.
    
    The Smallest x: We only need to find the first (smallest) number in the range [1,n] that meets the criteria.
    
    The Calculation: Once we find this smallest valid number (let's call it ans), every number from ans up to n is also valid.

##### C O D E 
```cpp
   class Solution {
    int   getSum(int N){
        int sum = 0;
        while(N!=0){
            sum += N%10;
            N = N/10;
        }
        return sum;
    }
  public:
    int getCount(int n, int d) {
            int low = 1, high = n;
            int ans = -1;
            while(low <= high){
                int mid = low +(high -low)/2;
                if(mid - getSum(mid) >= d){
                    ans = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
        if(ans == -1 ) return 0;
        if(ans != -1)    return (n-ans+1);
        
    }
            
};

```

