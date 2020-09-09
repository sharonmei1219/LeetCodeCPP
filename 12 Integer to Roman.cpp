class Solution {
public:
    string intToRoman(int num) {
    	static const vector<string> symbol{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    	static const vector<int>    value {1000, 900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,   1};
    	int remaining = num, symIndex = 0;
    	string result = "";
    	while (remaining > 0){
            if(remaining >= value[symIndex]){
            	result += symbol[symIndex];
            	remaining -= value[symIndex];
            }else{
            	symIndex ++;
            }
    	}
    	return result;
        
    }
};