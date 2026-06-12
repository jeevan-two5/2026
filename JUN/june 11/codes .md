##### WORD LADDER
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Base Case: Put all words in a set for O(1) lookup times.
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // Edge Case: If the endWord is not in the dictionary, we can never reach it.
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        
        // BFS Queue initialization
        queue<string> q;
        q.push(beginWord);
        
        // 'level' keeps track of the number of words in the shortest sequence
        int level = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            // Process all words at the current level
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                
                // If we reached the endWord, return the current path length
                if (word == endWord) {
                    return level;
                }
                
                // Try changing every character of the word from 'a' to 'z'
                for (int j = 0; j < word.length(); j++) {
                    char originalChar = word[j];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[j] = c; // Change one character
                        
                        // If this new word exists in our dictionary
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word); // Mark as visited by deleting it
                        }
                    }
                    
                    word[j] = originalChar; // Undo the change for the next position
                }
            }
            level++; // Move to the next level of transformations
        }
        
        return 0; // If queue becomes empty and we haven't reached endWord
    }
};

```
##### WORD LADDER 2
```cpp
  #include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, int> steps; // Stores the shortest distance of each word from beginWord
    vector<vector<string>> ans;       // Stores all valid shortest paths
    string bWord;

    // Step 2: DFS Backtracking to find all paths using the steps map
    void dfs(string word, vector<string>& path) {
        // Base Case: If we reach the beginWord, we have traced back a full path
        if (word == bWord) {
            vector<string> reversePath = path;
            reverse(reversePath.begin(), reversePath.end());
            ans.push_back(reversePath);
            return;
        }

        int currStep = steps[word];
        
        // Try changing every character to find the valid parent word
        for (int i = 0; i < word.length(); i++) {
            char originalChar = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                
                // A word is a valid parent if it exists in the steps map 
                // and its level is exactly 1 less than the current word's level
                if (steps.find(word) != steps.end() && steps[word] == currStep - 1) {
                    path.push_back(word);
                    dfs(word, path);
                    path.pop_back(); // Backtrack
                }
            }
            word[i] = originalChar; // Undo change
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // Edge Case: If endWord is not in dictionary, no path is possible
        if (dict.find(endWord) == dict.end()) {
            return {};
        }

        bWord = beginWord;
        queue<string> q;
        
        // Step 1: BFS to find the shortest distance levels from beginWord
        q.push(beginWord);
        steps[beginWord] = 1;
        dict.erase(beginWord); // Remove to avoid visiting again in the same layer

        bool foundEnd = false;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            
            int currStep = steps[word];
            
            if (word == endWord) {
                foundEnd = true;
                break;
            }

            // Generate all possible 1-letter transformations
            for (int i = 0; i < word.length(); i++) {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    
                    if (dict.find(word) != dict.end()) {
                        q.push(word);
                        steps[word] = currStep + 1;
                        dict.erase(word); // Remove from dictionary so other branches at higher levels don't reuse it
                    }
                    // Special case: if it's already visited in the *same* level by another node, 
                    // we still want to keep it in steps map for multiple paths
                    else if (steps.find(word) != steps.end() && steps[word] == currStep + 1) {
                        // Already found at the same level, do nothing
                    }
                }
                word[i] = originalChar;
            }
        }

        // If BFS completed and we found a path to endWord, trace paths back via DFS
        if (foundEnd) {
            vector<string> path;
            path.push_back(endWord);
            dfs(endWord, path); // Tracing backward from endWord to beginWord
        }

        return ans;
    }
};
```
##### SURROUNDED REGIONS
```cpp
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c, int rows, int cols) {
        // Base Cases: Out of bounds check or if the cell is not an 'O'
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
            return;
        }
        
        // Mark this cell as 'Safe' temporarily
        board[r][c] = '#';
        
        // Explore all 4 adjacent directions (Up, Down, Left, Right)
        dfs(board, r + 1, c, rows, cols);
        dfs(board, r - 1, c, rows, cols);
        dfs(board, r, c + 1, rows, cols);
        dfs(board, r, c - 1, rows, cols);
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Step 1: Scan Left and Right boundaries
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') dfs(board, r, 0, rows, cols);
            if (board[r][cols - 1] == 'O') dfs(board, r, r, cols - 1, rows, cols); 
            // Note: fixed boundary coordinates for safe traversal
        }
        
        // Scan Top and Bottom boundaries
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') dfs(board, 0, c, rows, cols);
            if (board[rows - 1][c] == 'O') dfs(board, rows - 1, c, rows, cols);
        }
        
        // Step 2: Traverse the entire board to flip cells to final states
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Surrounded 'O' gets captured
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O'; // Safe '#' goes back to 'O'
                }
            }
        }
    }
};
```
