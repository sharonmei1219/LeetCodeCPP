class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> resMap;
        vector<vector<string>> result;
        for(auto iter = strs.begin(); iter < strs.end(); iter ++){
            auto key = *iter;
            sort(key.begin(), key.end());
            resMap[key].push_back(*iter);
        }
        for(auto iter = resMap.begin(); iter != resMap.end(); iter ++){
            result.push_back(iter->second);
        }
        return result;
    }
};