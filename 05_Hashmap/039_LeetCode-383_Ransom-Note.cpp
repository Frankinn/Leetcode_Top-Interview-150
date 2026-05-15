/*
 * Top Interview 150 - 039 / 150
 * Problem: 383. Ransom Note
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Standard Hashmap
 * - Version 2: Frequency Array
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;
        int count[26] = {0};
        for(char c : magazine)
            ++count[c-'a'];
        for(char c : ransomNote){
            if(--count[c-'a'] < 0)
                return false;
        }
        return true;
        /*
        if(ransomNote.size() > magazine.size()) return false;
        std::unordered_map<char, int> umap;
        for(int i = 0; i < ransomNote.size(); ++i)
            ++umap[ransomNote[i]];
        int count = ransomNote.size();
        for(int i = 0; i < magazine.size(); ++i){
            if(umap.count(magazine[i])){
                if(--umap[magazine[i]] >= 0){
                    --count;
                    if(!count)
                        return true;
                }
            }
        }
        return false;
        */
    }
};