class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_left(height.size(), 0), max_right(height.size(), 0);
        int result = 0;
        for(int i = 1; i < height.size(); i++){
            max_left[i] = max(max_left[i-1], height[i-1]);
        }
        for(int j = height.size() - 2; j >= 0; j--){
            max_right[j] = max(max_right[j+1], height[j+1]);
        }
        for(int k = 0; k < height.size(); k++){
            int h = min(max_left[k], max_right[k]);
            if(height[k] > h) continue;
            result += h - height[k];
        }
        return result;
    }
};