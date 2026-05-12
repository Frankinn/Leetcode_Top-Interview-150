/*
 * Top Interview 150 - 028 / 150
 * Problem: 11. Container With Most Water
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Two Pointers Greedy
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        for(int i = 0, j = height.size()-1; i < j; ){
            maxWater = std::max(maxWater, (j-i)*std::min(height[i], height[j]));
            if(height[i] < height[j]){
                int last = height[i];
                ++i;
                while(i < j && height[i] <= last)
                    ++i;
            }
            else{
                int last = height[j];
                --j;
                while(i < j && height[j] <= last)
                    --j;
            }
            //height[i] < height[j] ? ++i : --j;
        }
        return maxWater;
    }
};