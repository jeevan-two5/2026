###### Q
<img width="707" height="607" alt="image" src="https://github.com/user-attachments/assets/0242563b-7ff3-4671-9601-eeb00a273e32" />

###### I N T U I T I O N
<img width="556" height="532" alt="image" src="https://github.com/user-attachments/assets/2328b277-399e-491e-810d-a59c8cba5d47" />
<img width="545" height="255" alt="image" src="https://github.com/user-attachments/assets/cb59a4f1-fbe6-4a78-a78b-e8d25433cd45" />

###### C-O-D-E
```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int calculateAreaAndSinkDFS(vector<vector<int>>& grid, int r, int c, int rows, int cols) {
        // Base Cases: If out of bounds or stepping on water (0), it contributes 0 to the area
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }
        
        // Sink the land cell to 0 so we don't visit it again
        grid[r][c] = 0;
        
        // Count this current cell (1) + find areas in all 4 neighboring directions
        int areaUp    = calculateAreaAndSinkDFS(grid, r - 1, c, rows, cols);
        int areaDown  = calculateAreaAndSinkDFS(grid, r + 1, c, rows, cols);
        int areaLeft  = calculateAreaAndSinkDFS(grid, r, c - 1, rows, cols);
        int areaRight = calculateAreaAndSinkDFS(grid, r, c + 1, rows, cols);
        
        // Sum them up and return total area of this branch
        return 1 + areaUp + areaDown + areaLeft + areaRight;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        
        // Iterate through every cell in the 2D grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If we find land (1), start calculating the size of this island
                if (grid[r][c] == 1) {
                    int currentIslandArea = calculateAreaAndSinkDFS(grid, r, c, rows, cols);
                    
                    // Keep track of the largest area seen so far
                    maxArea = max(maxArea, currentIslandArea);
                }
            }
        }
        
        return maxArea;
    }
};
```
