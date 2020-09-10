class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> result = {};
    	if(nums.size() <= 2) return result;
    	sort(nums.begin(), nums.end());
    	for(auto i = nums.begin(); i < prev(nums.end(),2); i++){
    		if(i != nums.begin() && *i == *(prev(i))) continue;
    		auto j = next(i);
            if(*i + *j > 0) break;
    		auto k = prev(nums.end());
    		while(j < k){
                const auto sumV = *i + *j + *k;
    			if(sumV == 0) result.push_back({*i, *j, *k});
                if(sumV >= 0) k--;
    			if(sumV <= 0) j++;
    		}
    	}
    	result.erase(unique(result.begin(), result.end()), result.end());
    	return result;
    }
};