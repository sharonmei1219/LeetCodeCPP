class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redTail = 0, blueHead = nums.size() - 1;
        int i = 0;
        while (i <= blueHead){
            if(nums[i] == 0){
                cout << i << redTail;
                swap(nums, i, redTail);
                redTail ++;
            }
            if(nums[i] == 2){
                swap(nums, i, blueHead);
                blueHead --;
                continue;
            }
            i++;
        }
    }
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};