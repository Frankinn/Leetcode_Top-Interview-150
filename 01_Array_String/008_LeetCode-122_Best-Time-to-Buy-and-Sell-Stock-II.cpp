/*
 * Top Interview 150 - 008 / 150
 * Problem: 122. Best Time to Buy and Sell Stock II
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: State-based Simulation
 * - Version 2: Greedy
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxGain = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i-1])
                maxGain += prices[i] - prices[i-1];
        }
        return maxGain;
        /*  //ver1
        int size = prices.size();
        if(!size) return 0;
        int ans = 0, min = prices[0];
        bool hold = true;
        for(int i = 1; i < prices.size(); ++i){
            if(hold && prices[i]-min > 0){
                ans += prices[i]-min;
                hold = false;
            }
            if(!hold || prices[i] < min){
                min = prices[i];
                hold = true;
            }
        }
        return ans;
        */
    }
};