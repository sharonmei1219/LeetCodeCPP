class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {{}};
        vector<vector<int>> result;
        for(auto iter = nums.begin(); iter < nums.end(); iter ++){
            auto subNums = filter(nums, *iter);
            auto subRes = permute(subNums);
            for(auto res = subRes.begin(); res < subRes.end(); res ++){
                result.push_back(pushFront(*res, *iter));
            }
        }
        return result;
    }
    
    vector<int> filter(vector<int> nums, int num){
        vector<int> result;
        for(auto iter = nums.begin(); iter < nums.end(); iter ++){
            if(*iter == num) continue;
            result.push_back(*iter);
        }
        return result;
    }
    
    vector<int> pushFront(vector<int> nums, int num){
        vector<int> result{num};
        for(auto iter = nums.begin(); iter < nums.end(); iter ++){
            result.push_back(*iter);
        }
        return result;
    }
};