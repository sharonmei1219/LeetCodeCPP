class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        const int h = findHead(nums);
        cout << h;
        return searchWithHead(nums, target, h, 0, nums.size());
    }

    int findHead(vector<int>& nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]) return i;
        }
        return 0;
    }
    
    int val(vector<int>& nums, int index, int h){
        const int i = (index + h)%nums.size();
        return nums[i];
    }
    
    bool searchWithHead(vector<int>& nums, int target, int h, int l, int r){
        if(r < l) return false;
        const int m = (l + r)/2;
        const int mV = val(nums, m, h);
        if(mV < target) return searchWithHead(nums, target, h, m+1, r);
        if(mV > target) return searchWithHead(nums, target, h, l, m-1);
        return true;
        
    }
};