class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        retrieveValidIP(s, 4, "", result);
        return result;
    }
    
    void retrieveValidIP(string s, int n, string ip, vector<string> & result){
        if(s.length() == 0) return;
        if(n == 1){
            if(s == "0" || ((s[0] != '0' && s.length() < 4 && stoi(s) <= 255))){
                ip = ip + s;
                result.push_back(ip);
                return;
            }
            return;
        }
        retrieveValidIP(s.substr(1, -1), n-1, ip+s.substr(0,1)+".", result);
        if(s[0] != '0'&& s.length() >= 2){
            retrieveValidIP(s.substr(2, -1), n-1, ip + s.substr(0,2) + ".", result);
            if(stoi(s.substr(0, 3)) <= 255 && s.length() >= 3){
                retrieveValidIP(s.substr(3, -1), n-1, ip + s.substr(0,3) + ".", result);
            }
        }
    }
};