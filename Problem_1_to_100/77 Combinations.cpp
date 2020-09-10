class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>  candidates;
        for(int i = 1; i <= n; i++){
            candidates.push_back(i);
        }
        return combineVector(candidates, k);
    }
    
    vector<vector<int>> combineVector(vector<int> candidates, int k){
        if(k == 1) return split(candidates);
        vector<int> temp = candidates;
        vector<vector<int>> result;
        while(temp.size() >= k){
            int head = temp.back();
            temp.pop_back();
            vector<vector<int>> tempRes = combineVector(temp, k - 1);
            for(auto iter = tempRes.begin(); iter < tempRes.end(); iter++){
                (*iter).push_back(head);
                result.push_back(*iter);
            }
        }
        return result;
    }
    
    vector<vector<int>> split(vector<int> candidates){
        vector<vector<int>> result;
        for(auto iter = candidates.begin(); iter < candidates.end(); iter ++){
            result.push_back({*iter});
        }
        return result;
    }
    
};