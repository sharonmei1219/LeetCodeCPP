class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        return comb(candidates.begin(), candidates.end(), target);
    }
    vector<vector<int>> comb(vector<int>::iterator begin, vector<int>::iterator end, int target){
        vector<vector<int>> result;
        if(target == 0) return {{}};
        if(*begin > target) return {};
        for(auto iter = begin; iter < end; iter++){
            auto res = comb(iter, end, target-*iter);
            for(auto itr = res.begin(); itr < res.end(); itr ++){
                (*itr).push_back(*iter);
                result.push_back(*itr);
            }
        }
        return result;
    }
};