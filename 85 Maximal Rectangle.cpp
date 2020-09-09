class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> row(n, 0);
        vector<vector<int>> hMatrix(m, row);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    hMatrix[i][j] = matrix[i][j] - '0';
                }else{
                    if(matrix[i][j] == '1'){
                        hMatrix[i][j] = 1 + hMatrix[i-1][j];
                    }else{
                        hMatrix[i][j] = 0;
                    }
                }
            }
        }
        
        int result = 0;
        for(int i = 0; i < m; i++){
            hMatrix[i].push_back(0);
            vector<int> hStack;
            for(int j = 0; j <= n; j++){
                while(hStack.size() > 0 && hMatrix[i][hStack.back()] > hMatrix[i][j]){
                    int h = hMatrix[i][hStack.back()];
                    int area = 0;
                    hStack.pop_back();
                    if(hStack.size() == 0){
                        area = h * j;
                    }else{
                        area = h * (j - hStack.back() - 1);
                    }
                    if(area > result) {result = area;}
                }
                hStack.push_back(j);
            }
        }
        return result;
    }
};