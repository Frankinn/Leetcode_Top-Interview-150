/*
 * Top Interview 150 - 002 / 150
 * Problem: 27. Remove Element
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Two Pointers - Head-to-Tail Swap
 */
 class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        /*if(nums.size() == 1){
            return (nums[0] == val ? 0 : 1);
        }*/
        for(int i = 0, j = nums.size(); i < j; ++i){
            if(nums[i] == val){
                ++k;
                --j;
                while(j>i){
                    if(nums[j] == val){
                        ++k;
                        --j;
                        continue;
                    }
                    nums[i] = nums[j];
                    break;
                }
            }
        }
        return nums.size() - k;
    }
};