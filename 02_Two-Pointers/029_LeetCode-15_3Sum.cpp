/*
 * Top Interview 150 - 029 / 150
 * Problem: 15. 3Sum
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Sort + Two Pointers + Pruning
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int t = 0; t < size-2; ++t){
            if(nums[t] > 0) break;
            if(t > 0 && nums[t] == nums[t-1]) continue;
            if(nums[t] + nums[t+1] + nums[t+2] > 0) break;
            if(nums[t] + nums[size-2] + nums[size-1] < 0) continue;

            for(int i = t+1, j = size-1; i < j; ){
                int sum = nums[i] + nums[j] + nums[t];
                if(sum == 0){
                    ans.push_back({nums[t], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[++i]){}
                    while(i < j && nums[j] == nums[--j]){}
                }
                else if(sum < 0)
                    ++i;
                else
                    --j;
            }
        }
        return ans;
    }
};