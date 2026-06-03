<img width="618" height="720" alt="image" src="https://github.com/user-attachments/assets/04d6fada-ca06-4595-8525-8229d6a6d244" />

###### INTUITION
<img width="523" height="364" alt="image" src="https://github.com/user-attachments/assets/29eebe1b-fa08-4471-94a7-8be6c9a54545" />
<img width="507" height="376" alt="image" src="https://github.com/user-attachments/assets/758262fc-7a0f-47ff-b4e0-2cb2c19e90dd" />


###### C O D E 
```cpp
// June3, 2026 - gfg potd
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> freqInInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // Step 1: Preprocess and map each number to its occurrence indices
        unordered_map<int, vector<int>> indexMap;
        for (int i = 0; i < arr.size(); i++) {
            indexMap[arr[i]].push_back(i);
        }

        vector<int> result;
        result.reserve(queries.size());

        // Step 2: Answer each query using Binary Search
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            // Base case: if x is not present in the array at all
            if (indexMap.find(x) == indexMap.end()) {
                result.push_back(0);
                continue;
            }

            const vector<int>& indices = indexMap[x];

            // Find the first index position that is >= l
            auto it1 = lower_bound(indices.begin(), indices.end(), l);
            // Find the first index position that is > r
            auto it2 = upper_bound(indices.begin(), indices.end(), r);

            // The difference between these positions gives the count
            result.push_back(it2 - it1);
        }

        return result;
    }
};
```

