class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> cntMap;
        for(auto iter = nums.begin(); iter < nums.end(); iter ++){
            cntMap[*iter] ++; 
        }
        
        return permNum(cntMap);
    }
    
    vector<vector<int>> permNum(map<int, int> & cntMap){
        vector<vector<int>> result;
        for(auto iter = cntMap.begin(); iter != cntMap.end(); iter ++){
            if(iter->second == 0) continue;
            cntMap[iter->first] --;
            auto subRes = permNum(cntMap);
            for(auto res = subRes.begin(); res < subRes.end(); res ++){
                result.push_back(pushFront(*res, iter->first));
            }
            cntMap[iter->first] ++;
        }
        if(result.size() == 0) result = {{}};
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