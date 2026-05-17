/*
 * Top Interview 150 - 049 / 150
 * Problem: 56. Merge Intervals
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Map-Based Bucket Sorting
 * - Version 2: Sort + Two-Pointer Look-Ahead
 * - Version 3: Sort + Direct Integration
 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(const auto& interval : intervals){
            int &back = ans.back()[1];
            if(interval[0] > back)
                ans.push_back(interval);
            else
                back = max(back, interval[1]);
        }
        return ans;
        /* //ver2
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); ++i){
            int j = i;
            int start = intervals[i][0], end = intervals[i][1];
            while(j + 1 < intervals.size() && end >= intervals[j+1][0]){
                ++j;
                end = max(end, intervals[j][1]);
            }
            //if(!ans.size() || intervals[j][0] > ans.back()[1])
                ans.push_back({start, end});
            i = j;
        }
        return ans;
        */
        /* //ver1
        unordered_map<int, vector<vector<int>>> umap;
        int maxStart = 0, minStart = INT_MAX;
        for(int i = 0; i < intervals.size(); ++i){
            umap[intervals[i][0]].emplace_back(intervals[i]);
            maxStart = max(maxStart, intervals[i][0]);
            minStart = min(minStart, intervals[i][0]);
        }
        auto maxEnd = [](vector<vector<int>>& v){
            int end = 0;
            for(int i = 0; i < v.size(); ++i)
                end = max(end, v[i][1]);
            return end;
        };
        auto nextMap = [&](int i){
            while(!umap.count(++i) && i <= maxStart);
            return i;
        };
        vector<vector<int>> ans;
        for(int i = minStart; i <= maxStart; i = nextMap(i)){
            if(umap.count(i)){
                int start = i, end = maxEnd(umap[i]);
                int j = nextMap(i);
                while(j <= maxStart && end >= j){
                    end = max(end, maxEnd(umap[j]));
                    i = j;
                    j = nextMap(j);
                }
                ans.push_back({start, end});
            }
        }
        return ans;
        */
    }
};