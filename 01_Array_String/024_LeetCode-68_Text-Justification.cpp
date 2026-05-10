/*
 * Top Interview 150 - 024 / 150
 * Problem: 68. Text Justification
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Manual State Tracking
 * - Version 2: Two-Pointer Range Calculation
 */
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int size = words.size();
        int i = 0;
        while(i < size){
            int j = i + 1;
            int len = words[i].size();
            while(j < size && len+1+words[j].size() <= maxWidth){
                len += words[j].size() + 1;
                ++j;
            }
            string line = words[i];
            int numWord = j - i, numSpace = maxWidth - (len - (numWord-1));
            if(j == size || numWord == 1){
                for(int k = i+1; k < j; ++k){
                    line.append(1, ' ');
                    line += words[k];
                }
                line.append(maxWidth - line.size(), ' ');
            }
            else{
                int midSpace = numSpace / (numWord-1);
                int extraSpace = numSpace % (numWord-1);
                for(int k = i+1; k < j; ++k){
                    int finalSpace = midSpace + (extraSpace-- > 0 ? 1 : 0);
                    line.append(finalSpace, ' ');
                    line += words[k];
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
        /*  //ver1
        vector<string> ans;
        if(words.size() == 1){
            ans.push_back(words[0]);
            ans[0].resize(maxWidth);
            for(int i = words[0].size(); i < maxWidth; ++i)
                ans[0][i] = ' ';
            return ans;
        }
        int cCount = words[0].size(), wCount = 1, ocCount = words[0].size();
        string str = words[0];
        int start = 1;
        for(int i = start; i < words.size(); ++i){
            cCount += words[i].size() + 1;  //charCount + space
            ocCount += words[i].size();  //only charCount
            ++wCount;  //wordCount
            if(cCount > maxWidth){
                cCount -= words[i].size() +1;
                ocCount -= words[i].size();
                --wCount;
                //--i;
                //int start = i-wCount;
                if(wCount == 1){
                    str.resize(maxWidth);
                    for(int j = words[start-1].size(); j < maxWidth; ++j)
                        str[j] = ' ';
                }
                else{
                    int space = maxWidth - ocCount;
                    int j = start;
                    while(j < start + space%(wCount-1)){
                        for(int k = 0; k < space/(wCount-1)+1; ++k)
                            str += " ";
                        str += words[j++];
                    }
                    while(j < start + wCount-1){
                        for(int k = 0; k < space/(wCount-1); ++k)
                            str += " ";
                        str += words[j++];
                    }
                }
                ans.push_back(str);
                str = words[i];
                cCount = words[i].size();
                ocCount = words[i].size();
                wCount = 1;
                start = i+1;
                if(i == words.size()-1){
                    str.resize(maxWidth);
                    for(int j = words[i].size(); j < maxWidth; ++j)
                        str[j] = ' ';
                    ans.push_back(str);
                    return ans;
                }
            }
            else if(i == words.size()-1){
                //int start = i-wCount;
                //str = words[start];
                if(wCount == 1){
                    str.resize(maxWidth);
                    for(int j = words[i].size(); j < maxWidth; ++j)
                        str[j] = ' ';
                }
                else{
                    for(int j = start; j < words.size(); ++j){
                        str += " ";
                        str += words[j];
                    }
                    int size = str.size();
                    if(size < maxWidth){
                        str.resize(maxWidth);
                        for(int j = size; j < maxWidth; ++j)
                            str[j] = ' ';
                    }
                    ans.push_back(str);
                }
                break;
            }
        }
        return ans;
        */
    }
};