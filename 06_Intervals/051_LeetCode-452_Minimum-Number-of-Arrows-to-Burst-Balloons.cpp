/*
 * Top Interview 150 - 051 / 150
 * Problem: 452. Minimum Number of Arrows to Burst Balloons
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Dynamic Overlap Tracking (Sort by Start)
 * - Version 2: Greedy Arrow Placement (Sort by End)
 */
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), 
            [](const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            });
        int arrow = 1, arrow_pos = points[0][1];
        for(const auto& point : points){
            if(point[0] > arrow_pos){
                ++arrow;
                arrow_pos = point[1];
            }
        }
        return arrow;
        /* //ver1
        if(points.size() == 1) return 1;
        sort(points.begin(), points.end());
        int ans = points.size();
        for(int i = 0; i < points.size(); ++i){
            int endLimit = points[i][1];
            while(i+1 < points.size() && points[i+1][0] <= endLimit){
                endLimit = min(endLimit, points[++i][1]); 
                --ans;
            }
        }
        return ans;
        */
    }
};