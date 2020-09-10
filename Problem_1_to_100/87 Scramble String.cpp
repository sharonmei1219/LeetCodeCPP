class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() == 0) return false;
        const int N = s1.length();
        vector<bool> row(N, false);
        vector<vector<bool>> matrix(N, row);
        vector<vector<vector<bool>>> table(N + 1, matrix);
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                table[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for(int n = 2; n <= N; n++){
            for(int i = 0; i <= N-n; i++){
                for(int j = 0; j <= N-n; j++){
                    for(int k = 1; k <= n-1; k++){
                        if((table[k][i][j] && table[n-k][i+k][j+k]) ||
                           (table[k][i][j+n-k] && table[n-k][i+k][j])){
                            table[n][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }

        return table[N][0][0];
    }
}