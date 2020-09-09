class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        map<int, int> numCnt;
        for(int i = 0; i < nums.size(); i++){
            numCnt[nums[i]] ++;
        }
        
        for(auto it = numCnt.begin(); it != numCnt.end(); it++){
            const int len = result.size();
            for(int i = 1; i <= it->second; i++){
                for(int j = len * (i - 1); j < len * i; j++){
                    vector<int> newSet = result[j];
                    newSet.push_back(it->first);
                    result.push_back(newSet);
                }
            }
        }
        return result;
    }
};