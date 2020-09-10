class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = 0;
        if(nums.size() < 3) return 0;
        result = nums[0] + nums[1] + nums[2];
        for(auto i = nums.begin(); i < prev(nums.end(), 2); i++){
        	auto j = next(i);
        	auto k = prev(nums.end());
        	while(j < k){
        		const auto sum = *i + *j + *k;
        		if (abs(sum-target) < abs(result-target)) result = sum;
        		if(sum <= target) j++;
        		if(sum >= target) k--;
        	}
        }
        return result;
    }
};