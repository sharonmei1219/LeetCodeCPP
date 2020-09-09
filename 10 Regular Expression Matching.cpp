
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isMatch(string s, string p) {
    	vector<string> patterns = partitionPattern(p);    	
    	return match(s, patterns, 0);
	}

	vector<string> partitionPattern(string p){
		vector<string> result = {};
		int pos = 0;
		int posOfStar = 0;

        int stackTop = p.length() - 1;
        while(stackTop >= 0){
        	int stackCur = stackTop;
        	if(p[stackCur] == '*'){
        		result.push_back(p.substr(stackCur - 1, 2));
        		stackTop = stackCur - 2;
        		continue;
        	}
        	
        	if(p[stackCur] == '.'){
        		while(stackCur >= 0 && p[stackCur] == '.') stackCur --;
                result.push_back(p.substr(stackCur + 1, stackTop - stackCur));
                stackTop = stackCur;
                continue;
        	}

        	while(stackCur >= 0 && p[stackCur] != '.' && p[stackCur] != '*') stackCur --;
            result.push_back(p.substr(stackCur + 1, stackTop - stackCur));
            stackTop = stackCur;

        }

        reverse(result.begin(), result.end());
        return result;
	}

	bool match(string s, vector<string> patterns, int pIndex){
		if(s.length() == 0 && pIndex == patterns.size()) return true;
		if(s.length() == 0 && !allStarNotation(patterns, pIndex)) return false;
		if(s.length() == 0 && allStarNotation(patterns, pIndex)) return true;
		if(s.length() != 0 && pIndex >= patterns.size()) return false;

		if(!isStarNotation(patterns[pIndex])){
			if(!matchFixedLengthStr(s, patterns[pIndex])) return false;
			return match(s.substr(patterns[pIndex].length(), string::npos), patterns, pIndex+1);
		}else{
			int pNonStarNotatiion = nextNoneStartNotation(patterns, pIndex);
			size_t sIndex = string::npos;
			if(pNonStarNotatiion != patterns.size()){
				sIndex = findMatchStr(s, 0, patterns[pNonStarNotatiion]);
				while (sIndex != string::npos){
					if (!matchStarNotations(s.substr(0, sIndex), patterns, pIndex, pNonStarNotatiion - 1)) return false;
					if(match(s.substr(sIndex + patterns[pNonStarNotatiion].length()), patterns, pNonStarNotatiion + 1)) return true;
					sIndex = findMatchStr(s, sIndex+1, patterns[pNonStarNotatiion]);
				}
				return false;
			}
			if (!matchStarNotations(s.substr(0, sIndex), patterns, pIndex, pNonStarNotatiion - 1)) return false;
			return true;
		}

		return false;
	}

    bool matchFixedLengthStr(string s, string p){
    	if(s.length() < p.length()) return false;
    	for(int i = 0; i < p.length(); i++){
    		if(p[i] != '.' && s[i] != p[i]) return false;
    	}
    	return true;
    }

    int findMatchStr(string s, int pos, string p){
    	if(p[0] == '.' && s.length() - pos >= p.length()) return pos;
    	return s.find(p, pos);
    }

	bool allStarNotation(vector<string> patterns, int pIndex){
		for(int i = pIndex; i< patterns.size(); i++){
			if(!isStarNotation(patterns[i])) return false;
		}
		return true;
	}

	bool isStarNotation(string notation){
		return notation.length() > 1 && notation[1] == '*';
	}

	int nextNoneStartNotation(vector<string> patterns, int index){
		for(int i = index; i< patterns.size(); i++){
			if(!isStarNotation(patterns[i])) return i;
		}
		return patterns.size();
	}

	bool matchStarNotations(string s, vector<string> patterns, int start, int end){
		string remaining = s;
		for(int i = start; i <=end; i++){
			if(patterns[i][0] == '.') return true;
			remaining = stripChar(remaining, patterns[i][0]);
		}
		if(remaining.length() == 0) return true;
		return false;
	}

	string stripChar(string s, char ch){
		for(int i = 0; i < s.length(); i++){
			if(s[i] != ch) return s.substr(i, string::npos);
		}
		return "";
	}

};