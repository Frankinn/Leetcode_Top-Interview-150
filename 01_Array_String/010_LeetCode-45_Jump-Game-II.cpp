/*
 * Top Interview 150 - 010 / 150
 * Problem: 45. Jump Game II
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: DP (O(n²))
 * - Version 2: Greedy
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return 0;
        int jumps = 0;
        int farthest = 0;
        int curEnd = 0;

        for(int i = 0; i < size; ++i){
            farthest = max(farthest, i + nums[i]);
            if(i == curEnd){
                ++jumps;
                curEnd = farthest;
                if(curEnd >= size-1)
                    break;
            }
        }
        return jumps;
        
        /*
        int size = nums.size();
        if(size == 1) return 0;
        if(size == 2) return 1;
        vector<int> step(size, size);
        step[0] = 0;
        step[1] = 1;
        for(int i = 2; i < size; ++i){
            int min = size;
            for(int j = i-1; j >=0; --j){
                if(nums[j] >= i-j)
                    min = std::min(min, step[j]+1);
            }
            step[i] = min;
        }
        return step.back();
        */
    }
};