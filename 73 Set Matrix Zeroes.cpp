class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int MaxY = matrix.size();
        if(MaxY == 0) return;
        const int MaxX = matrix[0].size();
        int markerY = -1, markerX = -1;
        for(int y = 0; y < MaxY; y++){
            for(int x = 0; x < MaxX; x ++){
                if(markerY == -1 && markerX == -1 && matrix[y][x] == 0){
                    markerY = y;
                    markerX = x;
                }else if(matrix[y][x] == 0){
                    matrix[y][markerX] = 0;
                    matrix[markerY][x] = 0;
                }
            }
        }
        
        if(markerX == -1 && markerY == -1) return;
        for(int y = 0; y < MaxY; y++){
            for(int x = 0; x < MaxX; x++){
                if(matrix[y][markerX] == 0 && y != markerY){
                    matrix[y][x] = 0;
                }
                if(matrix[markerY][x] == 0 && x != markerX){
                    matrix[y][x] = 0;
                }
            }
        }
    
        for(int x = 0; x < MaxX; x++){
            matrix[markerY][x] = 0;
        }
        
        for(int y = 0; y < MaxY; y++){
            matrix[y][markerX] = 0;
        }
        
    }
};