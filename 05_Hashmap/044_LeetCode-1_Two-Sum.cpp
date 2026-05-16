/*
 * Top Interview 150 - 044 / 150
 * Problem: 1. Two Sum
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: One-Pass Hash Map (O(n))
 * - Version 2: Sort with Two Pointers (O(nlogn))
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> umap;
        umap.reserve(size);
        for(int i = 0; i < size; ++i){
            if(auto it = umap.find(target - nums[i]); it != umap.end()){
                return {it->second, i};
            }
            umap[nums[i]] = i;
        }
        return {};
        /*
        vector<pair<int, int>> n(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            n[i].first = nums[i];
            n[i].second = i;
        }
        std::sort(n.begin(), n.end(), [](pair<int, int> a, pair<int, int> b){return a.first < b.first;});
        for(int i = 0, j = n.size()-1; i <= j; ){
            int plus = n[i].first + n[j].first;
            if(plus == target){
                auto [small, big] = std::minmax(n[i].second, n[j].second);
                return {small, big};
            }
            else if(plus < target)
                ++i;
            else
                --j;
        }
        return {0, 0};
        */
    }
};