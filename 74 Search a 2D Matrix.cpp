class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        const int width = matrix[0].size();
        int l = 0, r = matrix.size() * width - 1;
        while(l <= r){
            int m = (l + r) /2;
            int v = value(m, width, matrix);
            if(v < target){l = m + 1;}
            if(v > target){r = m - 1;}
            if(v == target) return true;
        }
        return false;
    }
    
    int value(int index, int width, vector<vector<int>>& matrix){
        int y = index/width, x = index%width;
        return matrix[y][x];
    }
};