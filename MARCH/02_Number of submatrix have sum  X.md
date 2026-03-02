###### I M A G E
<img width="1440" height="900" alt="image" src="https://github.com/user-attachments/assets/8c62ded0-d1ac-4b56-b41f-90b42e7fd7e6" />

###### I N T U I T I O N
2D Prefix Sum: Mundu oka pedda matrix build chestham, ekkada prati cell

(i, j) lo starting $(0,0)$ nundi aa point varaku unna elements

motham sum untundi. Deenivalla eh rectangle/square sum aina ventane kanukkovachu.

Square Fixed Size: Problem lo "Squares" matrame adigaru kabatti, 

manam oka side length k ni fix chestham.The $O(1)$ Formula: 

Okkasari size k fix ayyaka, eh point daggara square sum 

kavalanna ee chinna formula vaadathamu:

$$Sum = pref[i][j] - pref[i-k][j] - pref[i][j-k] + pref[i-k][j-k]$$

Ikkada Big Square nundi paina unna part, 

left lo unna part ni teesi, double minus aina corner ni add chestham.

Count: Ee $Sum == X$ (target) ayithe, count penchutham.

###### C O D E
```cpp
  class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = mat.size();
        int m= mat[0].size();
        
        vector<vector<long long>> pref(n+1,vector<long long>(m+1,0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= m; j++){
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
            }
        }
        int cnt = 0;
        int max_k = min(n,m);
        
        for(int k = 1; k<= max_k;k++){
            for(int i = k; i<= n;i++){
                for(int j = k; j<=m;j++){
                    long long cur_sum = pref[i][j] - pref[i-k][j] - pref[i][j-k]+pref[i-k][j-k];
                    if(cur_sum == x) cnt++;
                }
            }
        }
        return cnt;
    }
};
```
