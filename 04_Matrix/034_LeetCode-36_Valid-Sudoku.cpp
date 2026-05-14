/*
 * Top Interview 150 - 034 / 150
 * Problem: 36. Valid Sudoku
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Triple Pass
 * - Version 2: Single Pass with Bitmask
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};
        for(int r = 0; r < 9; ++r){
            for(int c = 0; c < 9; ++c){
                if(board[r][c] == '.') continue;
                int num = board[r][c] - '1';
                int mask = 1 << num;
                int boxIdx = (r/3)*3 + (c/3);
                if((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIdx] & mask)){
                    return false;
                }
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIdx] |= mask;
            }
        }
        return true;
        /* //ver1
        for(int row = 0; row < 9; ++row){
            vector<int> count(10);
            for(int col = 0; col < 9; ++col){
                char c = board[row][col];
                if(c != '.'){
                    ++count[c-'0'];
                    if(count[c-'0'] > 1)
                        return false;
                }
            }
        }
        for(int col = 0; col < 9; ++col){
            vector<int> count(10);
            for(int row = 0; row < 9; ++row){
                char c = board[row][col];
                if(c != '.'){
                    ++count[c-'0'];
                    if(count[c-'0'] > 1)
                        return false;
                }
            }
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                vector<int> count(10);
                for(int row = i; row < i+3; ++row){
                    for(int col = j; col < j+3; ++col){
                        char c = board[row][col];
                        if(c != '.'){
                            ++count[c-'0'];
                            if(count[c-'0'] > 1)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
        */
    }
};