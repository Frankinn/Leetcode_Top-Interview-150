/*
 * Top Interview 150 - 007 / 150
 * Problem: 121. Best Time to Buy and Sell Stock
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Manual Peak-Valley Tracking
 * - Version 2: Greedy
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxGain = 0;
        for(int price : prices){
            minPrice = min(minPrice, price);
            maxGain = max(maxGain, price - minPrice);
        }
        return maxGain;
        /*
        int size = prices.size();
        if(size == 1) return 0;
        int min = prices[0], max = prices[1];
        int ans = (max-min > 0 ? max-min : 0);
        for(int i = 1; i < size; ++i){
            if(prices[i] - min > ans){
                max = prices[i];
                ans = max-min;
            }
            if(prices[i] < min)
                min = prices[i];
        }
        return ans;
        */
    }
};