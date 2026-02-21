 ###### INCOMPLETE
```cpp
// incomplete
int n = citations.size();
        vector<int> bucket(n + 1, 0);

        // Step 1: Fill the buckets
        for (int c : citations) {
            if (c >= n) {
                bucket[n]++;
            } else {
                bucket[c]++;
            }
        }

        // Step 2: Iterate backwards to find the H-Index
        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += bucket[i]; // Total papers with at least i citations
            if (count >= i) {
                return i;
            }
        }

        return 0;
```
