class Solution {
public:
    int numDecodings(string s) {
        if(s == "0") return 0;
        if(s.length() <= 1) return 1;
        int n_2 = 1, n_1 = s[0] == '0' ? 0:1;
        int result = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2'){
                    result = n_2;
                }else{
                    return 0;
                }
            }else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                result = n_2 + n_1;
            }else{
                result = n_1;
            }
            n_2 = n_1;
            n_1 = result;
        }
        return result;
    }
};