class Solution {
public:
    string addBinary(string a, string b) {
        int carryOver = 0;
        string result;
        for(int aBit = a.length() - 1, bBit = b.length() - 1; aBit >= 0 && bBit >=0; aBit --, bBit--){
            int r = a[aBit] - '0' + b[bBit] - '0' + carryOver;
            carryOver = r/2;
            char bit = r%2 + '0';
            result = bit + result;
        }
        
        for(int aBit = a.length() - result.length() - 1; aBit >= 0; aBit --){
            int r = a[aBit] - '0' + carryOver;
            carryOver = r/2;
            char bit = r%2 + '0';
            result = bit + result;           
        }

        for(int bBit = b.length() - result.length() - 1; bBit >= 0; bBit --){
            int r = b[bBit] - '0' + carryOver;
            carryOver = r/2;
            char bit = r%2 + '0';
            result = bit + result;           
        }
        
        if(carryOver != 0) {result = '1' + result;}
        return result;
    }
};