class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        vector<vector<int>> result = {intervals[0]};
        
        for(auto iter = next(intervals.begin()); iter < intervals.end(); iter ++){
            auto temp = result.back();
            if((*iter)[0] <= temp[1]){
                cout << temp[0];
                result.pop_back();
                result.push_back({temp[0], max(temp[1], (*iter)[1])});
            }else{
                result.push_back(*iter);
            }
        }
        
        return result;
    }
};