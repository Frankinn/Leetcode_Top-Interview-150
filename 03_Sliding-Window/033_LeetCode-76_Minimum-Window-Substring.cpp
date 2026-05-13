/*
 * Top Interview 150 - 033 / 150
 * Problem: 76. Minimum Window Substring
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Sliding Window with Position Tracking
 * - Version 2: Sliding Window with Frequency Map
 */
class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        if(sSize < tSize) return "";
        int map[128] = {0};
        for(char c : t)
            ++map[c];
        int left = 0, right = 0;
        int counter = tSize, start = 0, minLen = INT_MAX;
        while(right < sSize){
            char rc = s[right];
            if(map[rc] > 0)
                --counter;
            --map[rc];
            ++right;
            while(counter == 0){
                if(right - left < minLen){
                    minLen = right - left;
                    start = left;
                }
                ++map[s[left]];
                if(map[s[left]] > 0)
                    ++counter;
                ++left;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
        /* //ver1
        int sSize = s.size(), tSize = t.size();
        if(sSize < tSize) return "";
        unordered_map<char, int> smap, tmap;
        for(int i = 0; i < tSize; ++i){
            ++tmap[t[i]];
        }
        vector<int> posi(sSize);
        int front = 1, back = 0;
        //string ans;
        int minLen = INT_MAX, minStart, reach = 0;
        int l = 0, r = 0;
        bool first = false;
        for( ; r < sSize; ++r){
            if(!tmap.count(s[r]))
                continue;
            if(!first){
                l = r;
                first = true;
            }
            posi[back++] = r;
            ++smap[s[r]];
            if(smap[s[r]] <= tmap[s[r]])
                ++reach;
            if(reach >= tSize){
                while(smap[s[l]] > tmap[s[l]]){
                    --smap[s[l]];
                    l = posi[front++];
                }
                minLen = r + 1 - l;
                minStart = l;
                ++r;
                break;
            }
        }
        for(; r < sSize; ++r){
            if(!tmap.count(s[r]))
                continue;
            posi[back++] = r;
            ++smap[s[r]];
                while(smap[s[l]] > tmap[s[l]]){
                    --smap[s[l]];
                    l = posi[front++];
                }
                if(minLen > r-l+1){
                    minLen = r-l+1;
                    minStart = l;
                }
            
        }
        return s.substr(minStart, minLen);
        */
    }
};