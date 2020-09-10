class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	return longestCommonPrefix(strs, 0, strs.size());
    }

    string longestCommonPrefix(vector<string>& strs, int begin, int end) {
    	if(begin == end) return "";
    	if(begin + 1 == end) return strs[begin];
    	const int mid = (begin + end)/2;
    	return combine(longestCommonPrefix(strs, begin, mid), longestCommonPrefix(strs, mid, end));
    }

    string combine(string str1, string str2){
    	string result = "";
    	int i = 0;
    	while(i<str1.length() && i < str2.length() && str1[i] == str2[i]){
    		result+=str1[i];
    		i++;
    	}
    	return result;
    }
};