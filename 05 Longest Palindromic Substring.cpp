class Solution {
public:
    string longestPalindrome(string s) {
    	string result = "";
    	for(int i = 0; i < s.length(); i++){
    		string sub1 = palindrom(s, i, i);
    		if (sub1.length() > result.length()) result = sub1;
    		string sub2 = palindrom(s, i, i+1);
    		if (sub2.length() > result.length()) result = sub2;
    	}
    	return result;
    }

    string palindrom(string s, int b, int f){
		while(b >=0 && f<s.length() && s[b] == s[f]){
			b --;
			f ++;
		}
		return s.substr(b+1, f-b-1);
    }
};