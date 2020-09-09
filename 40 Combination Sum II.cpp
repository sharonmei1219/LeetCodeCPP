class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        return comb2(candidates.begin(), candidates.end(), target);
    }

    vector<vector<int>> comb2(vector<int>::iterator begin, vector<int>::iterator end, int target){
        vector<vector<int>> result;
        if(begin == end) return {};
        if(target == *begin) return {{*begin}};
        if(*begin > target) return {};
        auto res = comb2(next(begin), end, target-*begin);
        for(auto itr = res.begin(); itr < res.end(); itr ++){
            (*itr).push_back(*begin);
            result.push_back(*itr);
        }
        if(next(begin) != end){
            auto n = upper_bound(begin, end, *begin);
            auto res2 = comb2(n, end, target);
            for(auto itr = res2.begin(); itr < res2.end(); itr ++){
                result.push_back(*itr);
            }
        }
        return result;
    }
};