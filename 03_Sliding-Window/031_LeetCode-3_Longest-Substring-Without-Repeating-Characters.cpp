/*
 * Top Interview 150 - 031 / 150
 * Problem: 3. Longest Substring Without Repeating Characters
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Sliding Window + Dictionary
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size <= 1) return size;
        //std::unordered_map<char, int> umap;
        int lastPos[128];
        memset(lastPos, -1, sizeof(lastPos));
        int maxLen = 0;
        for(int l = 0, r = 0; r < size; ++r){
            unsigned char c = s[r];
            if(lastPos[c] >= l)
                l = lastPos[c] + 1;
            lastPos[c] = r;
            maxLen = std::max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};