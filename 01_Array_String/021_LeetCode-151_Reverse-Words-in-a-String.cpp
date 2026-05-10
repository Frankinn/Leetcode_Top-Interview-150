/*
 * Top Interview 150 - 021 / 150
 * Problem: 151. Reverse Words in a String
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Manual Character Shifting
 * - Version 2: Two Pointers for Space Cleaning
 */
#include<utility>
class Solution {
public:
    string reverseWords(string s) {
        int slow = 0, size = s.size();
        for(int fast = 0; fast < size; ++fast){
            if(s[fast] != ' '){
                if(slow != 0)
                    s[slow++] = ' ';
                while(fast < size && s[fast] != ' ')
                    s[slow++] = s[fast++];
            }
        }
        size = slow;
        s.resize(size);
        auto begin = s.begin();
        reverse(begin, s.end());
        for(int i = 0, start = 0; i <= size; ++i){
            if(i == size || s[i] == ' '){
                reverse(begin+start, begin+i);
                start = i+1;
            }
        }
        return s;
        /*
        int mark = 0, size = (int)s.size();
        while(mark < size && s[mark] == ' ')
            ++mark;
        int shift = 0;
        for(int i = 0, j = mark; j < size; ++i, ++j){
            while(j < size-1 && s[j] == ' ' && s[j+1] == ' '){
                ++j;
                ++shift;
            }
            if(j >= size-1 && s[j] == ' '){
                mark = i;
                break;
            }
            s[i] = s[j];
            mark = i+1;
        }
        
        for(int i = 0, j = mark-1; i < j; ++i, --j){
            std::swap(s[i], s[j]);
        }
        
        for(int i = 0, end = 0; i < mark; ++i, ++end){
            while(end < mark && s[end] != ' ')
                ++end;
            for(int j = end-1; i < j; ++i, --j){
                std::swap(s[i], s[j]);
            }
            i = end;
        }
        s.resize(mark);
        return s;
        */
    }
};