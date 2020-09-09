class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int maxLength=0, curStart = 0, curEnd = 0;
    	for(curEnd = 0; curEnd < s.length(); curEnd++){
    		const int existingCharPos = s.find_first_of(s[curEnd], curStart);
    		if(existingCharPos >= curEnd){
    			if(curEnd - curStart + 1 > maxLength){
    				maxLength = curEnd - curStart + 1;
    			}
    		}else{
    			curStart = existingCharPos + 1;
    		}
    	}
        return maxLength;
    }
};