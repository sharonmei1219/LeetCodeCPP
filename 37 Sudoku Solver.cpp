class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> result(9, vector<char>(9, '.'));
        fillSudoku(board, 0, 0);
    }
    
    bool fillSudoku(vector<vector<char>>& board, int i, int j){
        if(i > 8) return true;
        int nexti = i, nextj = j;
        if(j == 8 ){
            nexti++;
            nextj = 0;
        }else{
            nextj++;
        }
        if(board[i][j] != '.'){
            return fillSudoku(board, nexti, nextj);
        }
        vector<char> candidate = validNum(board, i, j);
        for(auto it = candidate.begin(); it < candidate.end(); it++){
            board[i][j] = *it;
            if(fillSudoku(board, nexti, nextj)) return true;
        }
        board[i][j] = '.';
        return false;
    }
    
    bool isValidNum(vector<vector<char>> board, int i, int j){
        return isValidUnit(board, srow(i)) && isValidUnit(board, scolum(j)) && isValidUnit(board, sblock(i, j));
    }
    
    vector<tuple<int,int>> srow(int index){
        static map<int, vector<tuple<int, int>>> rows;
        if ( rows.find(index) != rows.end() ) return rows[index];
        vector<tuple<int,int>> result(9, {0, 0});
        for(int i = 0; i < 9; i++){
            result[i] = make_tuple(index, i);
        }
        rows[index] = result;
        return result;
    }
    vector<tuple<int,int>> scolum(int index){
        static map<int, vector<tuple<int, int>>> colums;
        if ( colums.find(index) != colums.end() ) return colums[index];
        vector<tuple<int,int>> result(9, {0, 0});
        for(int i = 0; i < 9; i++){
            result[i] = make_tuple(i, index);
        }
        colums[index] = result;
        return result;
    }
    vector<tuple<int,int>> sblock(int input_i, int input_j){
        int i = input_i- input_i%3;
        int j = input_j- input_j%3;
        static map<tuple<int, int>, std::vector<tuple<int, int>>> blocks;
        if ( blocks.find(make_tuple(i, j)) != blocks.end() ) return blocks[make_tuple(i, j)];
        vector<tuple<int,int>> result;
        for(int ii = i; ii < i + 3; ii++){
            for(int jj = j; jj < j + 3; jj++){
                result.push_back(make_tuple(ii,jj));
            }
        }
        blocks[make_tuple(i,j)] = result;
        return result;
    }
    bool isValidUnit(vector<vector<char>>& board, vector<tuple<int, int>> unit){
        vector<int> numCnt(unit.size(), 0);
        for(auto it = unit.begin(); it < unit.end(); it++){
            int i, j;
            tie(i, j) = *it;
            char c = board[i][j];
            if(c == '.') continue;
            if(numCnt[c-'1'] == 0) {numCnt[c-'1'] = 1; continue;};
            return false;
        }
        return true;
    }
    vector<char> validNum(vector<vector<char>> &board, int i, int j){
        vector<int> numCnt(9, 0);
        vector<tuple<int, int>> row = srow(i), col = scolum(j), block = sblock(i, j);
        for(auto it = row.begin(); it < row.end(); it++){
            int i, j;
            tie(i, j) = *it;
            if(board[i][j] == '.') continue;
            numCnt[board[i][j]-'1'] ++;
        }
        for(auto it = col.begin(); it < col.end(); it++){
            int i, j;
            tie(i, j) = *it;
            if(board[i][j] == '.') continue;
            numCnt[board[i][j]-'1'] ++;
        }
        for(auto it = block.begin(); it < block.end(); it++){
            int i, j;
            tie(i, j) = *it;
            if(board[i][j] == '.') continue;
            numCnt[board[i][j] -'1'] ++;
        }
        std::vector<char> result;
        for (char c = '1'; c <= '9'; c++){
            if(numCnt[c-'1'] == 0) result.push_back(c);
        }
        return result;

    }
};