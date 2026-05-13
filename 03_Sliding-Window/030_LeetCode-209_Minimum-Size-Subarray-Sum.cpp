/*
 * Top Interview 150 - 030 / 150
 * Problem: 209. Minimum Size Subarray Sum
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Sliding Window (O(n))
 * - Follow up: Prefix Sum with Binary Search (O(nlogn))
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int minLen = INT_MAX, sum = 0, l = 0;
        for(int r = 0; r < size; ++r){
            sum += nums[r];
            while(sum >= target){
                minLen = min(minLen, r-l+1);
                sum -= nums[l++];
            }
        }
        return (minLen == INT_MAX ? 0 : minLen);
        /* //Follow up
        int size = nums.size();
        int minLen = INT_MAX;
        vector<int> sums(size+1, 0);
        for(int i = 1; i <= size; ++i)
            sums[i] = sums[i-1] + nums[i-1];
        for(int i = 0; i < size; ++i){
            auto it = lower_bound(sums.begin(), sums.end(), target+sums[i]);
            if(it != sums.end())
                minLen = min(minLen, (int)distance(sums.begin(), it)-i);
        }
        return (minLen == INT_MAX) ? 0 : minLen;
        */
    }
};