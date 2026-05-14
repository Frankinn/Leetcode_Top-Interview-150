/*
 * Top Interview 150 - 037 / 150
 * Problem: 73. Set Matrix Zeroes
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Dual-Flag In-place Marking
 * - Version 2: Single-Flag In-place Marking
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool col0 = false;
        for(int i = 0; i < rows; ++i){
            if(matrix[i][0] == 0)
                col0 = true;
            for(int j = 1; j < cols; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = rows-1; i >= 0; --i){
            for(int j = cols-1; j >= 1; --j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(col0)
                matrix[i][0] = 0;
        }
        /* //ver1
        bool r0 = false, c0 = false;
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; ++i)
            if(!matrix[i][0]){
                c0 = true;
                break;
            }
        for(int j = 0; j < cols; ++j)
            if(!matrix[0][j]){
                r0 = true;
                break;
            }
        for(int i = 1; i < rows; ++i){
            for(int j = 1; j < cols; ++j)
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }

        for(int i = 1; i < rows; ++i){
            if(!matrix[i][0]){
                for(int j = 1; j < cols; ++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 1; j < cols; ++j){
            if(!matrix[0][j]){
                for(int i = 1; i < rows; ++i)
                    matrix[i][j] = 0;
            }
        }
        if(c0)
            for(int i = 0; i < rows; ++i)
                matrix[i][0] = 0;
        if(r0)
            for(int j = 0; j < cols; ++j)
                matrix[0][j] = 0;
        */
    }
};