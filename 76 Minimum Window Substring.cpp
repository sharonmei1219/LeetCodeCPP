class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tCharCnt = buildTargetStringCharCntMap(t);
        map<char, int> sCharCnt;
        vector<int> charPos;
        int leftIndex = 0;

        int r = seekR(s, tCharCnt, sCharCnt, charPos);
        if(r == -1) return "";
        if(charPos.size() == 1 && t.length() == 1) return t;
        
        int minL = charPos[leftIndex], minR = r;
        cout << minL << minR;
        
        
        while(r != -1){
            int lastL = charPos[leftIndex];
            sCharCnt[s[lastL]] --;
            leftIndex ++;
            int l = charPos[leftIndex];
            if(sCharCnt[s[lastL]] < tCharCnt[s[lastL]]){
                r = seekChar(s, s[lastL], r+1, sCharCnt, tCharCnt, charPos);
            }
            if(r == -1) continue;
            if(r - l < minR - minL){minR = r; minL = l;}
                
        }
        return s.substr(minL, minR - minL + 1);
    }

    map<char, int> buildTargetStringCharCntMap(string t){
        map<char, int> result;
        for(int i = 0; i < t.length(); i++){
            result[t[i]] ++;
        }
        return result;
    }
    
    int seekR(string s,  map<char, int>& tCharCnt, map<char, int>& sCharCnt, vector<int>& charPos){
        for(int i = 0; i < s.length(); i ++){
            auto iter = tCharCnt.find(s[i]);
            if(iter != tCharCnt.end()){
                sCharCnt[s[i]] ++;
                charPos.push_back(i);
                if(allIn(sCharCnt, tCharCnt)) return i;
            }
        }
        return -1;
    }
    
    int seekChar(string s, char target, int begin, map<char, int>& sCharCnt, map<char, int>& tCharCnt, vector<int>& charPos){
        for(int i = begin; i < s.length(); i++){
            auto iter = tCharCnt.find(s[i]);
            if(iter != tCharCnt.end()){
                sCharCnt[s[i]] ++;
                charPos.push_back(i);
            }
            if(s[i] == target) return i;
        }
        return -1;
    }
    
    bool allIn(map<char, int>& sCharCnt, map<char, int>& tCharCnt){
        for(auto iter = tCharCnt.begin(); iter != tCharCnt.end(); iter ++){
            auto sIter = sCharCnt.find(iter->first);
            if(sIter == sCharCnt.end()) return false;
            if(sIter->second < iter->second) return false;
        }
        return true;
    }
};