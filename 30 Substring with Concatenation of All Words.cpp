class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.size() == 0) return {};
        int l = totalSize(words), wSize = words[0].length();

        for(int offset = 0; offset < wSize; offset++){
            vector<string> matchedWords;
            map<string, int> restWordsCount;
            for(auto it = words.begin(); it < words.end(); it++){
                restWordsCount[*it] ++;
            }
            int i = offset;
            while(i < s.length()){
                string sub = s.substr(i, wSize);

                if(restWordsCount[sub] == 0){
                    if(matchedWords.size() == 0){
                        i += wSize;
                        continue;
                    }
                    restWordsCount[matchedWords[0]] ++;
                    matchedWords.erase(matchedWords.begin());
                    continue;
                }
    
                i += wSize;
                restWordsCount[sub] --;
                matchedWords.push_back(sub);
                if(totalCount(restWordsCount) == 0){
                    result.push_back(i - l);
                }
            }
        }
        return result;
    }

    int totalCount(map<string, int> &wordsCount){
        int result = 0;
        for(auto it = wordsCount.begin(); it != wordsCount.end(); it++){
            result += it->second;
        }
        return result;
    }

    int totalSize(vector<string> words){
        int result = 0;
        for(auto it = words.begin(); it < words.end(); it++){
            result += (*it).length();
        }
        return result;
    }
};