/*
 * Top Interview 150 - 026 / 150
 * Problem: 392. Is Subsequence
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Two Pointers Greedy
 * - Follow up: Precomputation with Binary Search
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        int sub = 0;
        for(char c : t){
            if(sub < s.size() && s[sub] == c)
                ++sub;
        }
        return sub == s.size();
        /*  //Follow up
        vector<int> indices[26];
        for(int i = 0; i < t.size(); ++i)
            indices[t[i]-'a'].push_back(i);
        int last = -1;
        for(char c : s){
            auto& list = indices[c-'a'];
            auto it = upper_bound(list.begin(), list.end(), last);
            if(it == list.end())
                return false;
            last = *it;
        }
        return true;
        */
    }
};