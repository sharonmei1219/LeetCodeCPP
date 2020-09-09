class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() == 0) return;
        int t1 = m-1, t2 = n-1, t = m + n - 1;
        while(t1 >= 0 && t2 >= 0){
            if(nums2[t2] > nums1[t1]){
                nums1[t] = nums2[t2];
                t --;
                t2 --;
            }else{
                nums1[t] = nums1[t1];
                t --;
                t1 --;
            }
        }
        while(t2 >= 0){
            nums1[t2] = nums2[t2];
            t2 --;
        }
        
    }
};