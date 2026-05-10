/*
 * Top Interview 150 - 023 / 150
 * Problem: 28. Find the Index of the First Occurrence in a String
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Optimized Brute Force (Two-End Comparison)
 * - Version 2: KMP (Knuth-Morris-Pratt) Algorithm
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int sizeH = haystack.size(), sizeN = needle.size();
        if(sizeN == 0) return 0;
        vector<int> lps(sizeN, 0);
        for(int i = 1, j = 0; i < sizeN; ++i){
            while(j > 0 && needle[i] != needle[j])
                j = lps[j-1];
            if(needle[i] == needle[j])
                lps[i] = ++j;
        }
        for(int i = 0, j = 0; i < sizeH; ++i){
            while(j > 0 && haystack[i] != needle[j])
                j = lps[j-1];
            if(haystack[i] == needle[j])
                ++j;
            if(j == sizeN)
                return i - sizeN + 1;
        }
        return -1;
        /*
        if(haystack.size() < needle.size()) return -1;
        if(needle.size() == 1){
            for(int i = 0; i < haystack.size(); ++i){
                if(haystack[i] == needle[0])
                    return i;
            }
            return -1;
        }
        char first = needle.front(), last = needle.back();
        for(int i = 0,j = needle.size()-1; j < haystack.size(); ++i, ++j){
            int next = 0;
            bool find = true;
            if(haystack[i] == first && haystack[j] == last){
                for(int a = i+1, b = j-1, c = 1, d = needle.size()-2; a <= b;++a, --b, ++c, --d){
                    if(haystack[a] != needle[c] || haystack[b] != needle[d]){
                        find = false;
                        if(!next)
                            next = a - 1;
                        break;
                    }
                    if(!next && a+needle.size()-1 < haystack.size() && haystack[a] == first && haystack[a+needle.size()-1] == last){
                        next = a - 1;
                    }
                }
                if(find){
                    return i;
                }
                else{
                    i = next;
                    j = next + needle.size() - 1;
                }
            }
        }
        return -1;
        */
    }
};