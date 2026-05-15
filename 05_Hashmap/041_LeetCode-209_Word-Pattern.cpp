/*
 * Top Interview 150 - 041 / 150
 * Problem: 290. Word Pattern
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Dual Hashmaps for Explicit Mapping
 * - Version 2: Last Occurrence Index Sync
 */
#include <sstream>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int cPos[26] = {0};
        unordered_map<string, int> sPos;
        stringstream ss(s);
        string word;
        int i = 0, size = pattern.size();
        while(ss >> word){
            if(i >= size) return false;
            int &cIdx = cPos[pattern[i]-'a'], &sIdx = sPos[word];
            if(cIdx != sIdx)
                return false;
            cIdx = sIdx = ++i;
        }
        return i == size;
        /*
        std::unordered_map<string, char> s2p;
        std::unordered_map<char, string> p2s;
        stringstream ss(s);
        string word;
        int i = 0, count = 0;
        for(; i < pattern.size(); ++i){
            if(ss >> word) ++count;
            if(p2s.count(pattern[i]) && p2s[pattern[i]] != word)
                return false;
            if(s2p.count(word) && s2p[word] != pattern[i])
                return false;
            p2s[pattern[i]] = word;
            s2p[word] = pattern[i];
        }
        if(i != count)
            return false;
        if(ss >> word)
            return false;
        return true;
        */
    }
};