/*
 * Top Interview 150 - 004 / 150
 * Problem: 80. Remove Duplicates from Sorted Array II (Medium)
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Manual State Tracking
 * - Version 2: General Two-Pointer Template (K-step Lookback)
 */
class Solution {
private:
    static const int MAX_TIMES = 2;
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= MAX_TIMES) return nums.size();
        int slow = MAX_TIMES;
        for(int fast = MAX_TIMES; fast < nums.size(); ++fast){
            if(nums[fast] != nums[slow-2]){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
        /*
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
        */
    }
};