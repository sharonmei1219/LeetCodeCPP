class Solution {
public:
    bool isMatch(string s, string p) {
        bool star = false;
        int sc = 0, pc = 0;
        int sb = 0, pb = 0;
        while(sc != s.length()){
            char pcv = pc >= p.length() ? '\0' : p[pc];
            // if(pc >= p.length()) return false; //problem here
            switch(pcv){
                case '?':
                    sc ++;
                    pc ++;
                    break;
                case '*':
                    star = true;
                    pb = pc;
                    sb = sc;
                    while(p[pb] == '*') pb++;
                    if(pb == p.length()) return true;
                    pc = pb;
                    break;
                default:
                    if(s[sc] == p[pc]){
                        sc++;
                        pc++;
                    }else{
                        if(!star) return false;
                        sb ++;
                        sc = sb;
                        pc = pb;
                    }
            }
        }
        
        while(p[pc] == '*' && pc < p.length()) pc++;
        return pc == p.length();
    }
};