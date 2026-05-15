/*
 * Top Interview 150 - 042 / 150
 * Problem: 242. Valid Anagram
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Frequency Serialization
 * - Version 2: Frequency Array Counter
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int alpha[26] = {0};
        for(char c : s)
            ++alpha[c-'a'];
        for(char c : t){
            if(--alpha[c-'a'] < 0)
                return false;
        }
        return true;
        /*
        auto toKey = [](string& s){
            int alpha[26] = {0};
            for(char& c : s)
                ++alpha[c - 'a'];
            string key = "";
            for(int i = 0; i < 26; ++i)
                key += to_string(alpha[i]) + "#";
            return key;
        };
        return toKey(s) == toKey(t);
        */
    }
};