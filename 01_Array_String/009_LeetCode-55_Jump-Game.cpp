/*
 * Top Interview 150 - 009 / 150
 * Problem: 55. Jump Game
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Recursive
 * - Version 2: Greedy
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0, size = nums.size();
        for(int i = 0; i < size; ++i){
            if(i > farthest)
                return false;
            farthest = max(farthest, i + nums[i]);
            if(farthest >= size-1)
                return true;
        }
        return false;
        /*
        if(nums.size()==1) return true;
        if(!nums[0]) return false;
        int& last = nums[nums.size()-1];
        bool change = false;
        if(!last){
            last = 1;
            change = true;
        }
        bool ans = jump(nums, nums.size()-1);
        if(change) last = 0;
        return ans;
        */
    }
    /*
    bool jump(vector<int>& nums, int p){  //ver1
        //if(!p) return true;
        while( p && nums[p]) --p;
        if(!p) return true;
        for(int i = p-1, dis = 2; i >= 0; --i, ++dis){
            if(nums[i] >= dis){
                if(jump(nums, i))
                    return true;
            }
        }
        return false;
    }
    */
};