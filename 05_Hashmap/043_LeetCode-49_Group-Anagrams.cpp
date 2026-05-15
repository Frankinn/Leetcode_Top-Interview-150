/*
 * Top Interview 150 - 043 / 150
 * Problem: 49. Group Anagrams
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Manual Map Comparison
 * - Version 2: Frequency Count Serialization
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        auto toKey = [](const string& s)->string{
            int alpha[26] = {0};
            for(char c : s)
                ++alpha[c - 'a'];
            string key(26, ' ');
            for(int i = 0; i < 26; ++i)
                key[i] = (char)(alpha[i]+1);  //for Leetcode test data
            return key;
        };
        std::unordered_map<string, int> umap;
        
        for(const string& s : strs){
            string key = toKey(s);
            if(!umap.count(key)){
                umap[key] = ans.size();
                ans.emplace_back();
                ans.back().push_back(s);
            }
            else{
                ans[umap[key]].push_back(s);
            }
        }
        return ans;

        /* //ver1
        vector<vector<string>> ans;
        if(strs.size() == 1){
            ans.emplace_back();
            ans[0].push_back(strs[0]);
            return ans;
        }
        vector<std::pair<std::unordered_map<char, int>, int>> maps;
        auto creatMap = [&](string& s){
            std::unordered_map<char, int> umap;
            int count = 0;
            for(int i = 0; i < s.size(); ++i){
                if(!umap.count(s[i]))
                    ++count;
                ++umap[s[i]];
            }
            maps.emplace_back(std::move(umap), count);
        };
        auto inMaps = [&](string& s){
            for(int i = 0; i < maps.size(); ++i){
                std::unordered_map<char, int> umap(maps[i].first);
                int count = 0;
                bool in = true;
                for(int j = 0; j < s.size(); ++j){
                    if(!umap.count(s[j])){
                        in = false;
                        break;
                    }
                    --umap[s[j]];
                    if(umap[s[j]] < 0){
                        in = false;
                        break;
                    }
                    if(umap[s[j]] == 0)
                        ++count;
                }
                if(in && count == maps[i].second)
                    return i;
            }
            return -1;
        };
        ans.emplace_back();
        ans[0].push_back(strs[0]);
        creatMap(strs[0]);
        for(int i = 1; i < strs.size(); ++i){
            int in = inMaps(strs[i]);
            if(in == -1){
                creatMap(strs[i]);
                ans.emplace_back();
                ans.back().push_back(strs[i]);
            }
            else{
                ans[in].push_back(strs[i]);
            }
        }
        return ans;
        */
    }
};