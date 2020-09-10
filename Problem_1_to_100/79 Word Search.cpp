class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        if(m == 0) return false;
        const int n = board[0].size();
        vector<bool> row(n, false);
        vector<vector<bool>> visited(m, row);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != word[0]) continue;
                if(searchBoard(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
    }
    
    bool searchBoard(vector<vector<char>>& board,
                     string word, int index,
                     int i,
                     int j,
                     vector<vector<bool>>& visited){

        if(index == word.length()-1) return board[i][j] == word[index];
     
        if(word[index] != board[i][j]) return false;
        visited[i][j] = true;
        if(toSearch(i, j+1, visited)
           && board[i][j+1] == word[index+1]
           && searchBoard(board, word, index+1, i, j+1, visited)) return true;
        if(toSearch(i, j-1, visited)
           && board[i][j-1] == word[index+1]
           && searchBoard(board, word, index+1, i, j-1, visited)) return true;
        if(toSearch(i+1, j, visited)
           && board[i+1][j] == word[index+1]
           && searchBoard(board, word, index+1, i+1, j, visited)) return true;
        if(toSearch(i-1, j, visited)
           && board[i-1][j] == word[index+1]
           && searchBoard(board, word, index+1, i-1, j, visited)) return true;
        visited[i][j] = false;
        return false;
    }
    
    bool toSearch(int i, int j, vector<vector<bool>>& visited){
        if(i < 0 || j < 0) return false;
        if(i >= visited.size() || j >= visited[0].size()) return false;
        return !visited[i][j];
    }
};