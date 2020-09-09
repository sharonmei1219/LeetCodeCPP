class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<int> unit(n, 0);
        vector<vector<int>> pathNums(m, unit);

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(i == 0 && j == 0){
                    pathNums[i][j] = 1;
                }else if(i == 0) {
                    pathNums[i][j] = pathNums[i][j-1];
                }else if(j == 0){ 
                    pathNums[i][j] = pathNums[i-1][j];
                }else{
                    pathNums[i][j] = pathNums[i][j-1] + pathNums[i-1][j];
                }
                if(obstacleGrid[i][j] == 1) pathNums[i][j] = 0;
            }
        }
return pathNums[m-1][n-1];
    }
};