/*
 * Top Interview 150 - 022 / 150
 * Problem: 6. Zigzag Conversion
 * ---------------------------------------------------------
 * Progress:
 * - Version 1: Manual Step Calculation (space O(1))
 * - Version 2: Row Simulation (space O(n))
 * - Version 3: Unified Cycle Pattern (space O(1))
 */
class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if(numRows == 1 || size <= numRows) return s;
        string ans;
        ans.reserve(size);
        int cycle = 2*numRows - 2;
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j+i < size; j += cycle){
                ans += s[i+j];
                int mid = j + cycle - i;  //(i+j) + cycle - 2i
                if(i != 0 && i != numRows-1 && mid < size)
                    ans += s[mid];
            }
        }
        return ans;
        /* //ver2, practice
        int size = s.size();
        if(size <= 2 || numRows == 1) return s;
        vector<string> rows(min(numRows, size));
        int curRow = 0;
        int posi = -1;
        for(char c : s){
            rows[curRow] += c;
            if(curRow == 0 || curRow == numRows-1)
                posi = -posi;
            curRow += posi;
        }
        string ans;
        for(string& row : rows)
            ans += row;
        return ans;
        */
        /*  //ver1
        int size = s.size();
        if(size <= 2 || numRows == 1) return s;
        string ans;
        ans.reserve(size);
        for(int j = 0; j < size; j += (numRows-1)*2)
            ans += s[j];
        for(int i = 1; i < numRows-1; ++i){
            bool jump = true;
            for(int j = i; j < size; ){
                ans += s[j];
                if(jump){
                    j += (numRows-i-1)*2;
                    jump = false;
                }
                else{
                    j += i*2;
                    jump = true;
                }
            }
        }
        for(int j = numRows-1; j < size; j += (numRows-1)*2)
            ans += s[j];
        return ans;
        */
    }
};