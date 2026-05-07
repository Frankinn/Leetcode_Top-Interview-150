/*
 * Top Interview 150 - 011 / 150
 * Problem: 274. H-Index
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Sort (O(nlogn))
 * - Version 2: Counting Sort (O(n))
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> buckets(size+1, 0);
        for(int citat : citations){
            if(citat >= size)
                ++buckets[size];
            else
                ++buckets[citat];
        }
        int count = 0;
        for(int i = size; i >= 0; --i){
            count += buckets[i];
            if(count >= i)
                return i;
        }
        return 0;
        /*
        std::sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        while(h < citations.size() && citations[h] >= h+1){
            ++h;
        }
        return h;
        */
    }
};