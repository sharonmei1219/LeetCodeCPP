class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.length(), n = word2.length();
        if(m == 0) return n;
        if(n == 0) return m;
        vector<int> row(n + 1, 0);
        vector<vector<int>> distance(m + 1, row);
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0) {distance[i][j] = j; continue;}
                if(j == 0) {distance[i][j] = i; continue;}
                const int insert = 1 + distance[i - 1][j];
                const int remove = 1 + distance[i][j - 1];
                const int replace = word1[i-1] == word2[j-1] ? distance[i-1][j-1] : distance[i-1][j-1]+1;
                distance[i][j] = min(insert, min(remove, replace));
            }
        }
        return distance[m][n];
    }
};