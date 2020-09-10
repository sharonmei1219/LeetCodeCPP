class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        auto it = prev(nums.end());
        while(it > nums.begin() && *prev(it) >= *it){
            it --;
        }
        auto low = it, high = prev(nums.end());
        while(high > low){
            int tmp = *low;
            *low = *high;
            *high = tmp;
            high --;
            low ++;
        }
        if(it == nums.begin()) return;
        auto incPos = prev(it);
        auto exchangePos = upper_bound(it, nums.end(), *incPos);
        int tmp = *incPos;
        *incPos = *exchangePos;
        *exchangePos = tmp;
    }
};