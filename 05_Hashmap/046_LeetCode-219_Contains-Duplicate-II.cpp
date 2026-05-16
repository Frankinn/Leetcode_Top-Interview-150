/*
 * Top Interview 150 - 046 / 150
 * Problem: 219. Contains Duplicate II
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Hash Map with Last Index Tracking
 * - Version 2: Sliding Window with Hash Set
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_set<int> uset;
        uset.reserve(min(size, k));
        for(int i = 0; i < size; ++i){
            if(i > k)
                uset.erase(nums[i-k-1]);
            if(!uset.insert(nums[i]).second)
                return true;
        }
        return false;
        /*
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); ++i){
            if(umap.count(nums[i]) && i - umap[nums[i]] <= k){
                return true;
            }
            umap[nums[i]] = i;
        }
        return false;
        */
    }
};