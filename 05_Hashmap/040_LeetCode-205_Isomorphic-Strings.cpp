/*
 * Top Interview 150 - 040 / 150
 * Problem: 383. Ransom Note
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Dual Hashmaps for Explicit Mapping
 * - Version 2: Last Occurrence Index Sync
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sPos[256] = {0};
        int tPos[256] = {0};
        for(int i = 0; i < s.size(); ++i){
            if(sPos[s[i]] != tPos[t[i]])
                return false;
            sPos[s[i]] = i + 1;
            tPos[t[i]] = i + 1;
        }
        return true;
        /* //ver1
        std::unordered_map<char, std::pair<int, int>> smap;
        std::unordered_map<char, std::pair<int, int>> tmap;
        for(int i = 0; i < s.size(); ++i){
            if(!smap.count(s[i])){
                if(tmap.count(t[i]))
                    return false;
                ++smap[s[i]].first;
                smap[s[i]].second = i;
                ++tmap[t[i]].first;
                tmap[t[i]].second = i;
            }
            else{  //smap.count(s[i]) > 0
                if(!tmap.count(t[i]))
                    return false;
                if(smap[s[i]].second != tmap[t[i]].second)
                    return false;
                ++smap[s[i]].first;
                smap[s[i]].second = i;
                ++tmap[t[i]].first;
                tmap[t[i]].second = i;
            }
        }
        return true;
        */
    }
};