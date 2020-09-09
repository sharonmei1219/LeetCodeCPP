class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() == 0) return {{}};
        vector<vector<int>> result;
        while(nums.size() > 0){
            int head = nums.back();
            nums.pop_back();
            vector<vector<int>> tempRes = subsets(nums);
            for(auto iter = tempRes.begin(); iter < tempRes.end(); iter ++){
                result.push_back(*iter);
                (*iter).push_back(head);
                result.push_back(*iter);
            }
        }
        return result;
    }
};