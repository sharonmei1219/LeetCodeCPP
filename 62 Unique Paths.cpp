class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> unit(n, 0);
        vector<vector<int>> pathNums(m, unit);

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(i == 0 && j == 0){
                    pathNums[i][j] = 1;
                    continue;
                }
                if(i == 0) {
                    pathNums[i][j] = pathNums[i][j-1];
                    continue;
                }
                if(j == 0){ 
                    pathNums[i][j] = pathNums[i-1][j];
                    continue;
                }
                pathNums[i][j] = pathNums[i][j-1] + pathNums[i-1][j];
            }
        }
        return pathNums[m-1][n-1];
        
    }
};