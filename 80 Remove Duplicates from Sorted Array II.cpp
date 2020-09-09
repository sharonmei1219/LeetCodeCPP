class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int len = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[len]){
                nums[len + 1] = nums[i];
                cout << -1 << nums[i] << len + 1;
                len ++;
            }else if(nums[i] == nums[len]){
                if(len == 0 || nums[i] != nums[len-1]){
                    nums[len + 1] = nums[i];
                    cout << -2 << nums[i] << len + 1;
                    len ++;
                }
            }
        }
        return len + 1;
    }
};