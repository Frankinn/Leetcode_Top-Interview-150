/*
 * Top Interview 150 - 013 / 150
 * Problem: 238. Product of Array Except Self
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Prefix & Suffix Products
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);
        ans[0] = 1;
        for(int i = 1; i < size; ++i){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int mult = 1;
        for(int i = size-1; i >= 0; --i){
            ans[i] *= mult;
            mult *= nums[i];
        }
        return ans;
    }
};