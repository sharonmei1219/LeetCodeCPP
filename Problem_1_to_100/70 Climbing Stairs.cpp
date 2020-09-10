class Solution {
public:
    int climbStairs(int n) {
       if(n <= 2) return n;
        int n_1 = 2, n_2 = 1;
        int result = 0;
        for(int i = 3; i <= n; i++){
            result = n_1 + n_2;
            n_2 = n_1;
            n_1 = result;
        }
        return result;
    }
};