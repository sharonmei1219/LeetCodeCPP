class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wordsCnt = 0, charCnt = 0, beginIndex = 0;
        vector<string> result;
        for(int i = 0; i < words.size(); i++){
            wordsCnt ++;
            charCnt += words[i].length();
            if(calTotalLen(wordsCnt, charCnt) > maxWidth){
                result.push_back(pack(beginIndex, i, words, wordsCnt - 1, charCnt - words[i].length(), maxWidth));
                wordsCnt = 1;
                charCnt = words[i].length();
                beginIndex = i;
            }
        }
        
        if(wordsCnt > 0){
            result.push_back(packLastLine(beginIndex, words.size(), words, wordsCnt, charCnt, maxWidth));
        }
        return result;
    }
    
    int calTotalLen(int wordsCnt, int charCnt){
        return charCnt + wordsCnt - 1;
    }
    
    string pack(int begin, int end, vector<string> words, int wordsCnt, int charCnt, int maxWidth){
        cout << maxWidth - charCnt;
        if(wordsCnt == 1){
            return appendSpace(words[begin], maxWidth - charCnt);
        }
        
        const int numOfSpace = maxWidth - charCnt;
        const int bigSpace = numOfSpace%(wordsCnt - 1) == 0 ? numOfSpace/(wordsCnt - 1) : numOfSpace/(wordsCnt - 1) + 1;
        const int smallSpace = numOfSpace/(wordsCnt - 1);
        
        const int numOfBigSpace = numOfSpace%(wordsCnt -1 );
        cout << bigSpace << smallSpace << numOfBigSpace;
        
        string result;
        for(int i = begin; i < begin + numOfBigSpace; i++){
            result = result + appendSpace(words[i], bigSpace);
        }
        
        for(int i = begin + numOfBigSpace; i < end - 1; i++){
            result = result + appendSpace(words[i], smallSpace);
        }
        
        result = result + words[end - 1];
        return result;
    }
    
    string packLastLine(int begin, int end, vector<string> words, int wordsCnt, int charCnt, int maxWidth){
        string result;
        const int numOfLastSpace = maxWidth - wordsCnt + 1 - charCnt;
        for(int i = begin; i < end - 1; i ++){
            result = result + words[i];
            result = result + ' ';
        }
        result = result + appendSpace(words[end-1], numOfLastSpace);
        return result;
    }
    
    string appendSpace(string inStr, int numOfSpace){
        string result = inStr;
        for(int i = 0; i < numOfSpace; i ++){
            result = result + ' ';
        }
        return result;
    }
};