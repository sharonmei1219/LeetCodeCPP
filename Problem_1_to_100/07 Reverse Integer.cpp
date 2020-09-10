class Solution {
public:
    int reverse(int x) {
    	int remain = x;
    	long result = 0;
    	while(remain != 0){
    		result = result * 10 + remain%10;
    		remain /= 10;
    	}
    	if(result > INT_MAX || result < INT_MIN) return 0;
    	return result;
    
    }
};