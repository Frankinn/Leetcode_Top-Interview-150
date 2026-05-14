/*
 * Top Interview 150 - 035 / 150
 * Problem: 54. Spiral Matrix
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Layer-based State Machine
 * - Version 2: Boundary Shrinking
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> ans;
        ans.reserve(rows*cols);
        int up = 0, down = rows-1, left = 0, right = cols-1;
        while(1){
            for(int i = left; i <= right; ++i)
                ans.push_back(matrix[up][i]);
            if(++up > down) break;
            for(int i = up; i <= down; ++i)
                ans.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; --i)
                ans.push_back(matrix[down][i]);
            if(--down < up) break;
            for(int i = down; i >= up; --i)
                ans.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return ans;
        /* //ver1
        vector<int> ans(matrix.size()*matrix[0].size());
        int index = 0;
        for(int start = 0, maxR = matrix.size(), maxC = matrix[0].size(); maxR>0 && maxC>0; ++start, maxR-=2, maxC-=2){
            for(int r = start, c = start, state = 0, count = maxR*maxC - (maxR>2 && maxC>2 ? (maxR-2)*(maxC-2) : 0); count > 0; --count){
                ans[index++] = matrix[r][c];
                if(state == 0 && c == start+maxC-1)
                    ++state;
                else if(state == 1 && r == start+maxR-1)
                    ++state;
                else if(state == 2 && c == start)
                    ++state;
                switch(state){
                    case 0:
                        ++c;
                        break;
                    case 1:
                        ++r;
                        break;
                    case 2:
                        --c;
                        break;
                    case 3:
                        --r;
                        break;
                }
            }
        }
        return ans;
        */
    }
};