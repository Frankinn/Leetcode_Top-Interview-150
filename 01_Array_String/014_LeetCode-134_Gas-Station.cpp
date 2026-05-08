/*
 * Top Interview 150 - 014 / 150
 * Problem: 134. Gas Station
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Peak & Valley Simulation
 * - Version 2: Greedy - Global & Local Surplus Tracking
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int curGas = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); ++i){
            int diff = gas[i] - cost[i];
            total += diff;
            curGas += diff;
            if(curGas < 0){
                start = i + 1;
                curGas = 0;
            }
        }
        return (total >= 0) ? start : -1;
        /* //ver1
		 // many peak(gas < cost), but only 1 solution,
		 // so only need to find the most peak.
        int size = gas.size();
        if (size == 1)
            return (gas[0] >= cost[0] ? 0 : -1);

        int lastCost = 0, lastCostPosi = 0, lastCostLen = 1;
        while(lastCostPosi < size && gas[lastCostPosi] >= cost[lastCostPosi]){
            ++lastCostPosi;
        }
        while(lastCostPosi < size && gas[lastCostPosi] <= cost[lastCostPosi]){
            ++lastCostPosi;
        }
        --lastCostPosi;
        lastCost = cost[lastCostPosi] - gas[lastCostPosi];
    {
        int i = (lastCostPosi+size-1)%size;
        while(i != lastCostPosi && gas[i] <= cost[i]){
            lastCost += cost[i] - gas[i];
            ++lastCostLen;
            i = (i+size-1)%size;
        }
    }
        if(lastCostLen >= size) return -1;

        int maxCost = lastCost, maxCostPosi = lastCostPosi, maxCostLen = lastCostLen;
        int curCost = 0, curCostPosi, curCostLen = 0;
        int maxGas = -1, maxGasPosi;
        int curGas = 0, curGasPosi, curGasLen = 0;
        int start = (maxCostPosi+1)%size;
    {
            int i = start;
        do{
            curGas = gas[i] - cost[i];
            curGasPosi = i;
            curGasLen = 1;
            i = (i+1)%size;  //avoid i == start
            while(i!=start && gas[i] >= cost[i]){
                curGas += gas[i] - cost[i];
                curGasPosi = i;
                ++curGasLen;
                i = (i+1)%size;
            }
            if(i == start) break;
            curCost = 0;
            curCostLen = 0;
            while(i != start && gas[i] <= cost[i]){
                curCost += cost[i] - gas[i];
                curCostPosi = i;
                ++curCostLen;
                i = (i+1)%size;
            }
            if(curCost >= curGas){
                lastCost += curCost - curGas;
                lastCostPosi = curCostPosi;
                lastCostLen += curGasLen + curCostLen;
                curCost = lastCost;
                curCostPosi = lastCostPosi;
                curCostLen = lastCostLen;
            }
            if(curCost > maxCost){
                maxCost = curCost;
                maxCostPosi = curCostPosi;
                maxCostLen = curCostLen;
            }
        }while(i != start);
    }
        int oil = 0;
        start = (maxCostPosi+1)%size;
    {
            int i = start;
        do{
            oil += gas[i] - cost[i];
            if(oil < 0) return -1;
            i = (i+1)%size;
        }while(i != start);
    }
    return start;
    */
    }
};