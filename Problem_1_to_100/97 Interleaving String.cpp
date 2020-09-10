class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int m = s1.length(), n = s2.length();
        if(m+n != s3.length()) return false;
        if(m == 0 && n == 0) return true;
        vector<bool> row(n+1, false);
        vector<vector<bool>> matrix(m+1, row);
        
        matrix[0][0] = true;
        for(int i = 0; i < n ; i++){
            matrix[0][i+1] = (matrix[0][i] && s2[i] == s3[i]);
        }
        
        for(int i = 0; i < m; i++){
            matrix[i+1][0] = (matrix[i][0] && s1[i] == s3[i]);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                matrix[i+1][j+1] = (matrix[i+1][j] && s3[i+j+1] == s2[j])
                    || (matrix[i][j+1] && s3[i+j+1] == s1[i]);
            }
        }
        
        return matrix[m][n];
    }
};