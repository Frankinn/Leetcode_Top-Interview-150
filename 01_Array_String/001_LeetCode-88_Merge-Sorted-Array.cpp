/*
 * Top Interview 150 - 001 / 150
 * Problem: 88. Merge Sorted Array
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Space O(m+n)
 * - Version 2: Space O(1)
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;
        while(p2 >= 0){
            if(p1 >= 0 && nums1[p1] > nums2[p2]){
                nums1[p--] = nums1[p1--];
            }
            else{
                nums1[p--] = nums2[p2--];
            }
        }
        /*  //original (v1)
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
        */
    }
};