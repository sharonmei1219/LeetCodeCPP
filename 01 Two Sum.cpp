class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> indexMap{};
        for(int i=0; i< nums.size(); i++){
            int expectedNum = target - nums[i];
            if(indexMap.count(expectedNum) == 1){
                return {indexMap[expectedNum], i};
            }
            indexMap[nums[i]] = i;
        }
        return {};
    }
};