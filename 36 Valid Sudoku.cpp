class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i ++){
            if(!isValidUnit(board, row(i))) {
                return false;
            }
            if(!isValidUnit(board, colum(i))) {
                cout << "colum " << i << endl;
                return false;
            }
        }
        for(int j = 0; j < 9; j += 3){
            for(int k = 0; k < 9; k +=3){
                if(!isValidUnit(board, block(j, k))) return false;
            }
        }
        return true;
    }
    vector<tuple<int,int>> row(int index){
        vector<tuple<int,int>> result(9, {0, 0});
        for(int i = 0; i < 9; i++){
            result[i] = make_tuple(index, i);
        }
        return result;
    }
    vector<tuple<int,int>> colum(int index){
        vector<tuple<int,int>> result(9, {0, 0});
        for(int i = 0; i < 9; i++){
            result[i] = make_tuple(i, index);
        }
        return result;
    }
    vector<tuple<int,int>> block(int i, int j){
        vector<tuple<int,int>> result;
        for(int ii = i; ii < i + 3; ii++){
            for(int jj = j; jj < j + 3; jj++){
                result.push_back(make_tuple(ii,jj));
            }
        }
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
};