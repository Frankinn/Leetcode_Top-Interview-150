/*
 * Top Interview 150 - 036 / 150
 * Problem: 48. Rotate Image
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Transpose and Reverse
 */
#include <utility>
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i = 0; i < size; ++i){
            for(int j = i; j < size; ++j)
                std::swap(matrix[i][j], matrix[j][i]);
        }
        
        for(int i = 0; i < size; ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};