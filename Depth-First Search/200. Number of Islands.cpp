/*
200. Number of Islands

- Algo: DFS
- Time: O(mn), m rows and n cols. 
- Space: O(mn), in worse case, if map filled with land and DFS goes by `m x n` deepth. 

*/

#include <vector>
#include <functional>
using namespace std; 

class Solution {
public: 
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()) return 0; 

        int ans = 0, rows = grid.size(), cols = grid[0].size();
        int dirs[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}}; // left, up, right, down 

        function<void(int,int)> dfs = [&](int r, int c){
            // validation check
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') { return ; }
            grid[r][c] = '0'; // marked current postion
            for (auto &[dr, dc] : dirs) {
                dfs(r + dr, c + dc);
            }
        };

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    ans++; 
                    dfs(r, c);
                }
            }
        }
        return ans; 
    }
};

