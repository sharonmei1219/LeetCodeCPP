class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        const int m = grid.size(), n = grid[0].size();
        vector<int> unit(n, 0);
        vector<vector<int>> minPath(m, unit);
        
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(i == 0 && j == 0){
                    minPath[i][j] = grid[i][j];
                }else if (i == 0){
                    minPath[i][j] = minPath[i][j-1] + grid[i][j];
                }else if (j == 0){
                    minPath[i][j] = minPath[i-1][j] + grid[i][j];
                }else{
                    minPath[i][j] = min(minPath[i-1][j], minPath[i][j-1]) + grid[i][j];
                }
            }
        }
        return minPath[m-1][n-1];
    }
};