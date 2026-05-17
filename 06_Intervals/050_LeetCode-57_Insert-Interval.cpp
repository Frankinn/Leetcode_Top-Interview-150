/*
 * Top Interview 150 - 050 / 150
 * Problem: 57. Insert Interval
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: In-place Manipulation
 * - Version 2: Three-Stage Linear Simulation
 * - Version 3: Binary Search Range Isolation
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        //first interval[1] >= newInterval[0]
        auto it_start = lower_bound(intervals.begin(), intervals.end(), newInterval[0], 
            [](const vector<int>& interval, int val){
                return interval[1] < val;
            });
        //first interval[0] > newInterval[1]
        auto it_end = upper_bound(intervals.begin(), intervals.end(), newInterval[1], 
            [](int val, vector<int>& interval){
                return val < interval[0];
            });
        if(it_start != it_end){
            newInterval[0] = min(newInterval[0], (*it_start)[0]);
            newInterval[1] = max(newInterval[1], (*(it_end-1))[1]);
        }
        ans.insert(ans.end(), intervals.begin(), it_start);
        ans.push_back(newInterval);
        ans.insert(ans.end(), it_end, intervals.end());
        return ans;
        /* //ver2
        //if(intervals.empty()) return {newInterval};
        vector<vector<int>> ans;
        int i = 0, size = intervals.size();
        ans.reserve(size+1);
        while(i < size && intervals[i][1] < newInterval[0]){
            ans.emplace_back(move(intervals[i++]));
        }
        while(i < size && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        ans.emplace_back(newInterval);
        while(i < size)
            ans.emplace_back(move(intervals[i++]));
        return ans;
        */
        /* //ver1
        auto it = upper_bound(intervals.begin(), intervals.end(), newInterval[0], [](int val, const vector<int>&a){return val < a[0];});
        if(it == intervals.end()){
            if(newInterval[0] > intervals.back()[1])
                intervals.emplace_back(newInterval);
            else{
                intervals.back()[0] = min(newInterval[0], intervals.back()[0]);
                intervals.back()[1] = max(newInterval[1], intervals.back()[1]);
            }
            return intervals;
        }
        if(it == intervals.begin()){
            if(newInterval[1] < intervals.front()[0]){
                intervals.insert(intervals.begin(), newInterval);
            }
            else{
                auto itr = it;
                while(itr != intervals.end() && newInterval[1] >= (*itr)[0])
                    ++itr;
                --itr;
                (*it)[0] = min((*it)[0], newInterval[0]);
                (*it)[1] = max((*itr)[1], newInterval[1]);
                if(it != itr){
                    if(++it == itr)
                        intervals.erase(it);
                    else
                        intervals.erase(it, itr+1);
                    }
            }
            return intervals;
        }
        if(newInterval[1] < (*it)[0] && newInterval[0] > (*(it-1))[1]){
            intervals.insert(it, newInterval);
        }
        else if(newInterval[1] >= (*it)[0] && newInterval[0] <= (*(it-1))[1]){
            auto itl = it-1, itr = it;
            while(itl != intervals.begin() && newInterval[0] <= (*itl)[1])
                --itl;
            while(itr != intervals.end() && newInterval[1] >= (*itr)[0])
                ++itr;
            if(newInterval[0] > (*itl)[1])
                ++itl;
            --itr;
            (*itl)[0] = min((*itl)[0], newInterval[0]);
            (*itl)[1] = max((*itr)[1], newInterval[1]);
            if(itl != itr){
                if(++itl == itr)
                    intervals.erase(itl);
                else
                    intervals.erase(itl, itr+1);
            }
                
        }
        /*
        else if(newInterval[0] <= (*(it-1))[1]){
            *(it-1)[1] = max(*(it-1)[1], newInterval[1]);
        }
        else if(newInterval[1] >= (*it)[0] && newInterval[0]){
            *(it)[0] = min(*(it)[0], newInterval[0]);
        }
        
        return intervals;
        */
    }
};