class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string sn_1 = countAndSay(n-1);
        string result = "";
        char lastC = sn_1[0];
        int cnt = 1;
        for(int i =  1; i < sn_1.length(); i++){
            if(sn_1[i] == lastC){
                cnt ++;
                continue;
            }
            result += to_string(cnt);
            result += lastC;
            cnt = 1 ;
            lastC = sn_1[i];
        }
        result += to_string(cnt);
        result += lastC;
        cnt = 1 ;
        lastC = sn_1[sn_1.length()-1];
        return result;
    }
};