class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int remain = x;
        long revert = 0;
        while(remain > 0){
        	revert = revert * 10 + remain%10;
        	remain /= 10;
        }
        if(revert == x) return true;
        return false;
    }
};