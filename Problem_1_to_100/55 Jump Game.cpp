class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLastJump = nums[0];
        int nextMax = 0;
        int curStep = 0;
        while(curStep <= maxLastJump && curStep < nums.size()){
            if(curStep + nums[curStep] > nextMax){
                nextMax = curStep + nums[curStep];
            }
            curStep ++;
            if(nextMax > maxLastJump){
                maxLastJump = nextMax;
            }
        }
        return nextMax >= nums.size() - 1;
        
    }
};