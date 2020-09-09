class Solution {
public:
    int romanToInt(string s) {
             	static const vector<string> symbol{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	static const vector<int>    value {1000, 900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
    	int symIndex = 0, result = 0;
    	string remaining = s;
    	while(remaining.length()>0){
    		while(remaining.find(symbol[symIndex]) == 0){
                result += value[symIndex];
                remaining = remaining.substr(symbol[symIndex].length(), string::npos);
    		}
    		symIndex ++;
    	}
    	return result;
    }
};