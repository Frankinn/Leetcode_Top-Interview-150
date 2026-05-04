/*
 * Top Interview 150 - 003 / 150
 * Problem: 26. Remove Duplicates from Sorted Array
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: 
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size() == 1) return 1;
        int i = 1, j = 1, k = 1, temp = nums[0];
        while(j < nums.size()){
            if(nums[j] == temp){
                ++j;
                continue;
            }
            if(nums[j] != temp){
                nums[i] = (temp = nums[j]);
                ++i;
                ++j;
                ++k;
            }
        }
        return k;
        /*
        while(nums[i] == nums[j] && j < nums.size()){
            ++i;
            ++j;
        }
        while(j < nums.size()){
            if(nums[j] != nums[j-1]){
                nums[i] = nums[j];
            }
        }
        for(int i=1, j=1, j < nums.size(); ++j){
            while(nums[j] == nums[j-1]) ++j;

        }
        return k;
        */
    }
};