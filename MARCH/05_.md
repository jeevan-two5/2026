###### I M A G E

<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/a5e8a63b-935c-4b34-b78a-b918494631e1" />

###### I N T U I T I O N

Summarize (Counting):You scan the entire matrix once to count 

how many 1s exist in each row and each column.

Think of row_count[i] and col_count[j] as a "census" of 

how many 1s live in that specific row or column.

Verify (Identifying):A position (i, j) is Special only if:

The value at that spot is 1.

That row has exactly one 1 (which must be at this spot).

That column has exactly one 1 (which must be at this spot).

Why it's efficient:Time: You only look at each cell twice ($O(m \times n)$).

Simplicity: It avoids complex nested loops or backtracking by using 

extra space (row_count and col_count) to store the state of the matrix.

###### C O D E
```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int>row_count(m,0);

        vector<int>col_count(n,0);

        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(mat[i][j] == 1){
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(mat[i][j] == 1 && row_count[i] == 1 && col_count[j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
```
