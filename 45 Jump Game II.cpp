class Solution {
public:
    
    int jump(vector<int> & nums){
        int r = 0;
        int nr = 0;
        int step = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > r){
                step++;
                r = nr;
            }
            nr = max(nr, i + nums[i]);
        }
        return step;
    }
};