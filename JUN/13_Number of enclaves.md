###### Q
<img width="776" height="533" alt="image" src="https://github.com/user-attachments/assets/75fff297-cdb7-43df-90b1-fadac5a159a5" />

###### I N T U I T I O N
<img width="593" height="693" alt="image" src="https://github.com/user-attachments/assets/ca58b262-dcee-4c19-9f33-d2b9ef0674fa" />


###### C O D E
```cpp
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        // Base Cases: Out of bounds check, or if the cell is already water (0)
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            // grid[r][c] == 0 handles both water and already-visited escape land
            return;
        }
        
        // Mark this land cell as visited by converting it to water (0)
        grid[r][c] = 0;
        
        // Explore all 4 adjacent directions (Up, Down, Left, Right)
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Scan Left and Right boundaries for escaping land
        for (int r = 0; r < rows; r++) {
            if (grid[r][0] == 1) dfs(grid, r, 0, rows, cols);
            if (grid[r][cols - 1] == 1) dfs(grid, r, cols - 1, rows, cols);
        }
        
        // Scan Top and Bottom boundaries for escaping land
        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 1) dfs(grid, 0, c, rows, cols);
            if (grid[rows - 1][c] == 1) dfs(grid, rows - 1, c, rows, cols);
        }
        
        // Step 2: Count the remaining 1s that couldn't escape
        int enclaveCount = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    enclaveCount++;
                }
            }
        }
        
        return enclaveCount;
    }
};
```
