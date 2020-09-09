class Solution {
public:
    int search(vector<int>& nums, int target) {
        int offset = 0;
        while(offset + 1 < nums.size() && nums[offset] < nums[offset + 1]){
            offset ++;
        }
        vector<int> sortedNums(nums.size());
        for(int i = 0; i <nums.size(); i++){
            sortedNums[i] = nums[(i + offset + 1)%nums.size()];
        }
        for(int i = 0; i < nums.size(); i++){
            if(sortedNums[i] > target) return -1;
            cout << offset << i;
            if(sortedNums[i] == target) return (i + offset + 1)%nums.size();
        }
        return -1;
    }
};