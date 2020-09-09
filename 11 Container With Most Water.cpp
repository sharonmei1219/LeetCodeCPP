class Solution {
public:
    int maxArea(vector<int>& height) {
    	int result = 0, i = 0, j = height.size() - 1;
		while(i < j){
			if(height[i] < height[j]){
                int v = height[i] * (j-i);
                if(v>result) result = v;
				i++;
			}else{
                int v = height[j] * (j-i);
                if(v>result) result = v;
				j--;
			}
		}
    	return result;
    }

};