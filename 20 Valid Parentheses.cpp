class Solution {
public:
    bool isValid(string s) {
        stack<char> cstack;
        map<char, char> closingMap{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for(int i = 0; i < s.length(); i ++){
            switch(s[i]){
                case '(':
                case '{':
                case '[':
                    cstack.push(closingMap[s[i]]);
                    break;
                case ')':
                case '}':
                case ']':
                    if(cstack.size() == 0) return false;
                    if(cstack.top() != s[i]) return false;
                    cstack.pop();
                    break;
                default:
                    break;
            }
        }
        return cstack.size() == 0;
    }
};