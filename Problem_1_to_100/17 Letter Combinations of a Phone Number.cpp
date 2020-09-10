class Solution {
public:
    vector<string> letterCombinations(string digits) {

        static map<char, vector<string>> charMap {
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}},
        };
        
        if(digits.length() == 1) return charMap[digits[0]];        
        if(digits.length() == 0) return {};
        
        vector<string> result = {};
        const vector<string> remainderResults = letterCombinations(digits.substr(1, string::npos));
        for(int i = 0; i < charMap[digits[0]].size(); i++){
            for(int j = 0; j < remainderResults.size(); j++){
                result.push_back(charMap[digits[0]][i] + remainderResults[j]);
            }
        }
        return result;
    }
};