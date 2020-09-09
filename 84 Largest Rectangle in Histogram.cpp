class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> sortedStack;
        heights.push_back(0);
        int result = 0;
        for(int i = 0; i < heights.size(); i++){
            while(sortedStack.size() > 0 && heights[sortedStack.back()] > heights[i]){
                int h = heights[sortedStack.back()];
                sortedStack.pop_back();
                int area = 0;
                if(sortedStack.size() == 0){
                    area = i * h;
                }else{
                    area = (i - sortedStack.back() - 1)*h;
                }
                if(area > result){result = area;}
            }
            sortedStack.push_back(i);
        }

        return result;
    }
};