class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result = {0};
        for(int i = 0; i < n; i++){
            const int len = result.size();
            const int toAdd = 1 << i;
            for(int j = len - 1; j >= 0; j--){
                result.push_back(result[j] + toAdd);
            }
        }
        return result;
    }
};