/*
 * Top Interview 150 - 048 / 150
 * Problem: 228. Summary Ranges
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Value Gap Detection with Tail Patching
 * - Version 2: Two-Pointer Interval Expansion
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        //if(size == 0) return {};
        vector<string> ans;
        for(int i = 0; i < size; ++i){
            int start = i;
            while(i+1 < size && nums[i+1] == nums[i]+1)
                ++i;
            if(start == i)
                ans.push_back(to_string(nums[start]));
            else
                ans.push_back(to_string(nums[start])+"->"+to_string(nums[i]));
        }
        return ans;
        /*
        if(!nums.size()) return vector<string>();
        string str = to_string(nums[0]);
        if(nums.size() == 1) return vector<string>(1, str);
        vector<string> ans;
        int size = nums.size();
        for(int i = 1, start = 0; i < size; ++i){
            if(nums[i] > nums[i-1] + 1){
                if(i-1 > start)
                    str += "->" + to_string(nums[i-1]);
                ans.push_back(str);
                start = i;
                str = to_string(nums[i]);
            }
        }
        if(nums[size-1] == nums[size-2] + 1)
            str += "->" + to_string(nums[size-1]);
        ans.push_back(str);
        return ans;
        */
    }
};