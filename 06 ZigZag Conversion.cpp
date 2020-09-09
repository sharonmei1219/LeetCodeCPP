class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        const int periodic = 2 * (numRows - 1);
        if (numRows == 1) return s;
        result = extract1(s, periodic, 0);
        for(int offset = 1; offset < numRows - 1; offset ++){
        	result += extract2(s, periodic, offset);
        }
        result += extract1(s, periodic, numRows - 1);
        return result;
    }

    string extract1(string s, int periodic, int offset){
    	string result = "";
    	for(int i = offset; i < s.length(); i = i + periodic){
    		result += s[i];
    	}
    	return result;
    }

    string extract2(string s, int periodic, int offset){
    	string result = "";
    	for(int i = offset, j = periodic - offset; i < s.length(); i += periodic, j += periodic){
    		result += s[i];
    		if(j<s.length()){
    			result += s[j];
    		}
    	}
    	return result;
    }
};