###### I N T U I T I O N

    You simulate the tower row by row.
    
    prev_row stores how much champagne each glass in the previous row currently has.
    
    For each glass, if it has more than 1 cup, the extra (prev_row[i] - 1) overflows.
    
    That extra is split equally (0.5 each) to the two glasses just below it in the next row.
    
    You keep repeating this process until you reach query_row.
    
    Finally, you return min(1.0, prev_row[query_glass]) because a glass can hold at most 1 cup.
    
    👉 So basically:
    You simulate overflow level by level, always carrying only the previous row (space optimized DP).

    
###### C O D E
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
