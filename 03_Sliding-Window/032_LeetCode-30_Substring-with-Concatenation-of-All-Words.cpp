/*
 * Top Interview 150 - 032 / 150
 * Problem: 30. Substring with Concatenation of All Words
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Index-Tracking with List
 * - Version 2: Sliding Window with Frequency Map
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int sSize = s.size(), wordNum = words.size(), len = words[0].size();
        if(sSize < wordNum * len) return ans;
        unordered_map<string_view, int> wordCount;
        unordered_map<string_view, int> window;
        string_view sv = s;  //string_view's lifecycle < string's lifecycle
        for(string_view w : words)
            ++wordCount[w];
        for(int i = 0; i < len; ++i){
            int left = i, right = i, count = 0;
            while(right + len <= sSize){
                string_view w = sv.substr(right, len);
                right += len;
                if(wordCount.count(w)){
                    ++window[w];
                    ++count;
                    while(window[w] > wordCount[w]){
                        string_view leftWord = sv.substr(left, len);
                        --window[leftWord];
                        --count;
                        left += len;
                    }
                    if(count == wordNum)
                        ans.push_back(left);
                }
                else{
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
            window.clear();
        }
        return ans;
        /* //ver1
        vector<int> ans;
        int wSize = words[0].size(), amount = words.size();
        if(s.size() < amount * wSize)
            return ans;
        auto equal = [&](const int& start, const string& word){
            for(int i = start, j = 0; j < wSize; ++i, ++j){
                if(i == s.size())
                    return false;
                if(s[i] != word[j])
                    return false;
            }
            return true;
        };
        auto in = [&](const int& p){
            for(int i = 0; i < amount; ++i){
                if(equal(p, words[i])){
                    return i;
                }
            }
            return -1;
        };
        std::unordered_map<string, list<int>> umap;
        for(int i = 0; i < amount; ++i){
            umap[words[i]].push_back(-1);
        }
        int count = 0;
        //int last = s.size() - wSize;
        for(int mod = 0; mod < wSize; ++mod){
            for(int l = mod, r = mod; r < s.size(); r += wSize){
                int element = in(r);
                if(element >= 0){  //s.substr(r, wSize) == words[n]
                    if(umap[words[element]].front() == -1){  //first time{
                        umap[words[element]].push_back(r);
                        umap[words[element]].pop_front();
                    }
                    else if(umap[words[element]].front() >= l && umap[words[element]].front() % wSize == r % wSize){  //repeat
                        l = umap[words[element]].front() + wSize;
                        if(umap[words[element]].size() == 1){
                            umap[words[element]].front() = r;
                        }
                        else{
                            umap[words[element]].push_back(r);
                            umap[words[element]].pop_front();  //{0, 3}->{3, 6}
                        }
                    }
                    else{
                        umap[words[element]].push_back(r);
                        umap[words[element]].pop_front();
                    }
                }
                else{  //element == -1 (not found)
                    l = r + wSize;
                    continue;
                }
                if((r-l) / wSize == amount - 1){
                    ans.push_back(l);
                    l += wSize;
                }
            }
        }
        return ans;
        */
    }
};