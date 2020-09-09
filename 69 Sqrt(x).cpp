class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int left = 1, right = x;
        while(left <= right){
            const int mid = left + (right - left)/2;
            if(mid > x/mid){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return right;
    }
};