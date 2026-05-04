/*
 * Top Interview 150 - 001 / 150
 * Problem: 88. Merge Sorted Array
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Original (Space O(m+n)) - AC
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n)
            return;
        if(!m){
            for(int m0 = 0; m0 < n; ++m0)
                nums1[m0] = nums2[m0];
            return;
        }
        vector<int> num(nums1.begin(), nums1.end());
        for(int m0=0, n0=0, mn=0; mn < m+n;){
            if(m0 >= m){
                for(;n0 < n; ++mn,++n0){
                    nums1[mn] = nums2[n0];
                }
                return;
            }
            if(n0 >= n){
                for(;m0 < m; ++mn,++m0){
                    nums1[mn] = num[m0];
                }
                return;
            }
            if(num[m0] <= nums2[n0]){
                nums1[mn] = num[m0];
                ++mn;
                ++m0;
            }
            else{
                nums1[mn] = nums2[n0];
                ++mn;
                ++n0;
            }
        }
    }
};