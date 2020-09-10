class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int nineCnt = 0;
        for(auto iter = prev(digits.end()); iter >= digits.begin(); iter--){
            if(*iter == 9) {
                nineCnt ++;
                continue;
            }
            break;
        }
        
        const int headCnt = digits.size() - nineCnt;
        vector<int> result;
        
        if(headCnt == 0){
            result.push_back(0);
        }
        
        for(int i = 0; i < headCnt; i++){
            result.push_back(digits[i]);
        }
        
        auto end = prev(result.end());
        *end = *end + 1;
        
        for(int i = 0; i < nineCnt; i++){
            result.push_back(0);
        }
        return result;
        
    }
};