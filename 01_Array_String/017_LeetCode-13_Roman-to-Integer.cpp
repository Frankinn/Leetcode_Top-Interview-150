/*
 * Top Interview 150 - 017 / 150
 * Problem: 13. Roman to Integer
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Single Pass with Switch
 */
class Solution {
private:
    //std::unordered_map<char, int> umap;
public:
    int romanToInt(string s) {
        int ans = 0, size = s.size();
        auto getVal = [](char c)->int{
            switch(c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        };
        for(int i = 0; i < size; ++i){
            if(i < size-1 && getVal(s[i]) < getVal(s[i+1])){
                ans -= getVal(s[i]);
            }
            else
                ans += getVal(s[i]);
        }
        return ans;
    }
};