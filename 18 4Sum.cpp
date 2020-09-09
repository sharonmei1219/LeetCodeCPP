class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        vector<vector<int>> result = {};
        sort(nums.begin(), nums.end());
        for(auto i = nums.begin(); i < prev(nums.end(), 3); i++){
            // if(*i > target) break;
            if(i!=nums.begin() && *i == *prev(i)) continue;
            for(auto j = next(i); j < prev(nums.end(), 2); j++){
                // if(*i + *j > target) break;
                if(prev(j) > i && *j == *prev(j)) continue;
                auto k = next(j);
                auto l = prev(nums.end());
                while(k < l){
                    const auto sum = *i + *j + *k + *l;
                    if(sum == target) result.push_back({*i, *j, *k, *l});
                    if(sum <= target) k++;
                    if(sum >= target) l--;
                }
            }
        }
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};