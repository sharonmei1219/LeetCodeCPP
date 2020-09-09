class Solution {
public:
    vector<string> generateParenthesis(int n) {
        map<pair<int, int>, vector<string>> res;
        return genNthParenthesis(n, 0, 0, res);
    }
    vector<string> genNthParenthesis(int n, int openCnt, int closeCnt, map<pair<int, int>,vector<string>> & res) {
        if(openCnt == n && closeCnt == n) return {""};
        if(res.find(make_pair(openCnt, closeCnt)) != res.end()) return res[make_pair(openCnt, closeCnt)];
        vector<string> result;
        if(openCnt < n){
            auto remainder = genNthParenthesis(n, openCnt + 1, closeCnt, res);
            for(auto i = remainder.begin(); i < remainder.end(); i++){
                result.push_back("(" + *i);
            }
        }
        if(closeCnt < openCnt){
            auto remainder = genNthParenthesis(n, openCnt, closeCnt+1, res);
            for(auto i = remainder.begin(); i < remainder.end(); i++){
                result.push_back(")" + *i);
            }
        }
        res[make_pair(openCnt, closeCnt)] = result;
        return result;
    }
};