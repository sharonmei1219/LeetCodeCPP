class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEnding = 0, maxSum = INT_MIN;
        for(auto iter = nums.begin(); iter < nums.end(); iter ++){
            maxEnding += *iter;
            if(maxEnding > maxSum) maxSum = maxEnding;
            if(maxEnding < 0) maxEnding = 0;
        }
        return maxSum;
    }
};