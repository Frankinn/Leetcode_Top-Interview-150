/*
 * Top Interview 150 - 047 / 150
 * Problem: 128. Longest Consecutive Sequence
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Dynamic Boundary Merging
 * - Version 2: Hash Set Intelligent Scan
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        for(int num : numSet){
            if(!numSet.count(num-1)){  //smallest
                int curNum = num, curLen = 1;
                while(numSet.count(++curNum)){
                    ++curLen;
                }
                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
        /*
        unordered_map<int, pair<int, int>> umap;  //num, min, max
        int maxLen = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(umap.count(nums[i]))
                continue;
            umap[nums[i]] = {nums[i], nums[i]};
            pair<int, int>& now = umap[nums[i]];
            bool plus1 = umap.count(nums[i]+1), minus1 = umap.count(nums[i]-1);
            if(plus1 && minus1){
                pair<int, int>& max = umap[umap[nums[i]+1].second];
                pair<int, int>& min = umap[umap[nums[i]-1].first];
                now.first = max.first = min.first;
                now.second = min.second = max.second;
            }
            else if(plus1){
                pair<int, int>& max = umap[umap[nums[i]+1].second];
                max.first = nums[i];
                now.second = max.second;
            }
            else if(minus1){
                pair<int, int>& min = umap[umap[nums[i]-1].first];
                min.second = nums[i];
                now.first = min.first;
            }
            if(now.second - now.first + 1 > maxLen)
                maxLen = now.second - now.first + 1;
        }
        return maxLen;
        */
    }
};