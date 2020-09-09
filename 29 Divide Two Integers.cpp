class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned long remainder = dividend > 0 ? dividend : -(long long)dividend;
        unsigned long factor = divisor > 0 ? divisor : -(long long)divisor;
        unsigned long result = 0;
        while(remainder >= factor){
            unsigned long  sum = factor;
            for(int i = 0; remainder >= sum; i++){
                remainder -= sum;
                sum <<= 1;
                result += 1 << i;
            }
        }

        if(((unsigned long) dividend >> 31) ^ ((unsigned long) divisor >> 31)){
            return result > 0x80000000 ? INT_MIN:-result;
        }
        
        return result > INT_MAX ? INT_MAX:result;
    }
};