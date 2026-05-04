/*
 * Top Interview 150 - 004 / 150
 * Problem: 80. Remove Duplicates from Sorted Array II (Medium)
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Original
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size() == 1) return 1;
        if(nums.size() == 2) return 2;
        int slow = 1;
        bool check = (nums[0] == nums[1]);
        for(int fast = 1; fast < nums.size(); ++fast){
            if(nums[fast] != nums[fast-1]){
                nums[slow++] = nums[fast];
                check = true;
            }
            else if(check){
                nums[slow++] = nums[fast];
                check = false;
            }
        }
        return slow;
    }
};