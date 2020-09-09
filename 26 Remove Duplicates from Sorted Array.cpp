class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto j = nums.begin();
        for (auto i = nums.begin(); i < nums.end(); i++){
            if(*i != *j){
                j++;
                *j = *i;
            }
        }
        if(j<nums.end()) nums.erase(next(j), nums.end());
        return nums.size();
    }
};