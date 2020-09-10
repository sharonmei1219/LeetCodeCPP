#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::endl;
using std::cout;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        return solvePartialQueens(n, n);
    }
    
    vector<vector<string>> solvePartialQueens(int row, int n){
        if(row == 1) return initialRes(n);
        vector<vector<string>> res;
        auto partialRes = solvePartialQueens(row - 1, n);

        for(auto iter = partialRes.begin(); iter < partialRes.end(); iter++){
            auto oneRes = fillRow(*iter, n);
            std::move(oneRes.begin(), oneRes.end(), std::back_inserter(res));
        }
        return res;
    }
    
    vector<vector<string>> fillRow(vector<string> oneRes, int n){
        vector<vector<string>> res;
        for(int i = 0; i < n; i++){
            if(validatePosInRow(oneRes, i)){
                auto newRes = oneRes;
                newRes.push_back(buildStr(n, i));
                res.push_back(newRes);
            }
        }
        return res;
    }
    
    bool validatePosInRow(vector<string> oneRes, int pos){
        for(auto iter = oneRes.begin(); iter < oneRes.end(); iter ++){
            if((*iter)[pos] == 'Q') return false;
        }
        const int resSize = oneRes.size();
        for(int i = 0; i < oneRes.size(); i++){
            if(pos - resSize + i >= 0){
                if(oneRes[i][pos - resSize + i] == 'Q') return false;
            }
            if(pos + resSize - i < oneRes[i].length()){
                if(oneRes[i][pos + resSize - i] == 'Q') return false;
            }
        }
        
        return true;
    }

    vector<vector<string>> initialRes(int n){
        vector<vector<string>> res;
        for(int i = 0; i < n; i ++){
            vector<string> oneRes{buildStr(n, i)};
            res.push_back(oneRes);
        }
        return res;
    }
    
    string buildStr(int n, int pos){
        string res(n, '.');
        res[pos] = 'Q';
        return res;
    }
    

};