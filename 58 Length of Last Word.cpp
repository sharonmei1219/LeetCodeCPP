class Solution {
public:
    int lengthOfLastWord(string s) {
        const int len = s.length();
        if(len == 0) return 0;
        int cCur = len - 1, lastLen = 0;
        while(cCur >= 0 && s[cCur] == ' ' ){cCur --;}
        while(cCur >= 0){
            if(s[cCur] == ' ') break;
            lastLen ++;
            cCur --;
        }
        return lastLen;
        
    }
};