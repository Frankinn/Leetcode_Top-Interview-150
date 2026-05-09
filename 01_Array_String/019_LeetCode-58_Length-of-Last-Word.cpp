/*
 * Top Interview 150 - 019 / 150
 * Problem: 58. Length of Last Word
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Forward Scan
 * - Version 2: Backward Scan
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i = s.size()-1; i >= 0; --i){
            if(s[i] != ' '){
                while(i >=0 && s[i] != ' '){
                    ++ans;
                    --i;
                }
                return ans;
            }
        }
        return ans;

        /*
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            bool space = false;
            if(s[i] == ' '){
                space = true;
                while(s[i] == ' ' && i < s.size()){
                    ++i;
                }
                if(i >= s.size())
                    return ans;
                ans = 0;
            }
            ++ans;
        }
        return ans;
        */
    }
};