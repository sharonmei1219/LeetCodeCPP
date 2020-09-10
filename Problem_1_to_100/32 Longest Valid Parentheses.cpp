class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> openBraces;
        vector<int> lens(s.length(), 0);
        int maxLength = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') openBraces.push(i);
            if(s[i] == ')' && openBraces.size() > 0){
                int j = openBraces.top();
                lens[i] = i - j + 1;
                if(j-1 > 0) lens[i] += lens[j-1];
                if(lens[i] > maxLength) maxLength = lens[i];
                openBraces.pop();
            } 
        }
        return maxLength;
    }
};