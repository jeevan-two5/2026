###### Q
<img width="701" height="315" alt="image" src="https://github.com/user-attachments/assets/9238463c-aa73-44e0-9856-636cd1c6869b" />

###### I N T U I T I O N
<img width="552" height="290" alt="image" src="https://github.com/user-attachments/assets/5eb0dbb4-61ff-4396-aa4e-f546207f3fe4" />
<img width="564" height="486" alt="image" src="https://github.com/user-attachments/assets/c12dcd5b-bd5f-4d28-9319-dc34d91f2fae" />



###### C - O - D - E

```cpp
#include <vector>

using namespace std;

class Solution {
private:
    void sinkIslandDFS(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        // Base Cases: If we are out of bounds or step on water ('0'), stop exploring
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
            return;
        }
        
        // "Sink" the current land piece by turning it into water ('0')
        grid[r][c] = '0';
        
        // Recursively visit all 4 adjacent directions
        sinkIslandDFS(grid, r + 1, c, rows, cols); // Down
        sinkIslandDFS(grid, r - 1, c, rows, cols); // Up
        sinkIslandDFS(grid, r, c + 1, rows, cols); // Right
        sinkIslandDFS(grid, r, c - 1, rows, cols); // Left
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        
        // Step 1: Traverse through every cell in the 2D grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Step 2: If we find dry land ('1'), we found a new island!
                if (grid[r][c] == '1') {
                    islandCount++; // Increment our answer
                    
                    // Step 3: Trigger DFS to sink this entire connected island
                    sinkIslandDFS(grid, r, c, rows, cols);
                }
            }
        }
        
        return islandCount;
    }
};
```
