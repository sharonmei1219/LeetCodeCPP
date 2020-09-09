class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int totalLength = nums1.size() + nums2.size();
        if (totalLength%2 == 1) return findElementSortedArrays(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, totalLength/2);
        const double mid1 = findElementSortedArrays(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, totalLength/2-1);
        const double mid2 = findElementSortedArrays(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, totalLength/2);
        return (mid1 + mid2)/2;
    }

    double findElementSortedArrays(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int m){
        if (end2 < start2) return nums1[m - start2];
        if (end1 < start1) return nums2[m - start1];



        const int mid1 = (end1 + start1)/2, mind1Value = nums1[mid1];
        const int mid2 = findNum(nums2, start2, end2, mind1Value);
        if(mid1 + mid2 > m) return findElementSortedArrays(nums1, start1, mid1-1, nums2, start2, mid2, m);
        if(mid1 + mid2 < m - 1) return findElementSortedArrays(nums1, mid1 + 1, end1, nums2, mid2, end2, m);
        if(mid1 + mid2 == m) return nums1[mid1];
        if(mid2 >= nums2.size()) return nums1[mid1+1];
        if(nums1[mid1] < nums2[mid2]){
            if(mid1 < nums1.size() - 1 ){
                if(nums1[mid1+1] <nums2[mid2]){
                    return nums1[mid1+1];
                }else{
                    return nums2[mid2];
                }
                
            }else{
                return nums2[mid2];
            }
        }
            return nums1[mid1];
        
         // return nums1[mid1] < nums2[mid2] ? nums2[mid2] : nums1[mid1];  
        }


    int findNum(vector<int> nums, int start, int end, int target){
        if (start > end || start>=nums.size()) return start;
        const int mid = (start + end)/2, midValue = nums[mid];
        if(target < midValue) return findNum(nums, start, mid - 1, target);
        if(target > midValue) return findNum(nums, mid + 1, end, target);
        return mid;
    }
};