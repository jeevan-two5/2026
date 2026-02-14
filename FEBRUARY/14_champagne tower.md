```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Equivalent to: prev_row = [poured]
        std::vector<double> prev_row = {(double)poured};

        // Equivalent to: for row in range(1, query_row + 1)
        for (int row = 1; row <= query_row; ++row) {
            // Equivalent to: cur_row = [0] * (row + 1)
            std::vector<double> cur_row(row + 1, 0.0);
            
            // Equivalent to: for i in range(row)
            for (int i = 0; i < row; ++i) {
                // Equivalent to: extra = prev_row[i] - 1
                double extra = prev_row[i] - 1.0;
                
                // Equivalent to: if extra > 0
                if (extra > 0) {
                    // Split the excess equally between the two glasses below
                    cur_row[i] += 0.5 * extra;
                    cur_row[i + 1] += 0.5 * extra;
                }
            }
            // Move to the next row
            prev_row = cur_row;
        }

        // Return the amount in the target glass, capped at 1.0
        // Equivalent to: return min(1, prev_row[query_glass])
        return std::min(1.0, prev_row[query_glass]);
    }
};
```
