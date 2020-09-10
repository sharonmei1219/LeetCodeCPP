class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        const int h = matrix.size();
        for(int i = 0; i <= h/2; i ++){
            for(int j = i; j < h - i - 1; j++){
                int temp = matrix[j][h-i-1];
                matrix[j][h-i-1] = matrix[i][j];
                matrix[i][j] = matrix[h-j-1][i];
                matrix[h-j-1][i] = matrix[h-i-1][h-j-1];
                matrix[h-i-1][h-j-1] = temp;
            }
        }
    }
};