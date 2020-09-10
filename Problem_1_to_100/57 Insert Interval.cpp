class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        sort(intervals.begin(), 
             intervals.end(),
             [](vector<int> a, vector<int>b){return a[0] < b[0];}
            );
        vector<vector<int>> result = {intervals[0]};
        auto lb = lower_bound(intervals.begin(),
                         intervals.end(),
                          newInterval,
                         [](vector<int> a, vector<int>b){return a[0] < b[0];}
                        );
        
        for(auto iter = next(intervals.begin()); iter < lb; iter ++){
            result.push_back(*iter);
        }
    
       auto tmp = result.back();
       if (tmp[1] >= newInterval[0]){
           vector<int> combinedInterval = {tmp[0], max(tmp[1], newInterval[1])};
           result.pop_back();
           result.push_back(combinedInterval);
       }else{
           result.push_back(newInterval);
       }
        
        if(lb == intervals.begin()){
            result = {newInterval};
        }
        
        for (auto iter = lb; iter < intervals.end(); iter ++){
           auto tmp = result.back();
           if (tmp[1] >= (*iter)[0]){
               vector<int> combinedInterval = {tmp[0], max(tmp[1], (*iter)[1])};
               result.pop_back();
               result.push_back(combinedInterval);
           }else{
                result.push_back(*iter);
           }
        }

        return result;
    }
};