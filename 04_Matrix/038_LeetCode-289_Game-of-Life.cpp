/*
 * Top Interview 150 - 038 / 150
 * Problem: 289. Game of Life
 * ---------------------------------------------------------
 * Progress: 
 * - Version 1: Integer Marking
 * - Version 2: Bit Manipulation
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                int count = 0;  //liveNeighbors
                int& cur = board[i][j];
                for(int r = max(0, i-1); r <= min(rows-1, i+1); ++r){
                    for(int c = max(0, j-1); c <= min(cols-1, j+1); ++c){
                        if((r != i || c != j) && board[r][c] & 1)
                            ++count;
                    }
                }

                if((cur & 1) && (count == 2 || count == 3))
                    cur |= 2;
                if(!(cur & 1) && (count == 3))
                    cur |= 2;
            }
        }
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                board[i][j] >>= 1;
            }
        }
        /* //ver1
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] > 0){
                    if(i > 0){
                        if(int &u = board[i-1][j]; u > 0) ++u; else --u;
                        if(j > 0) if(int &ul = board[i-1][j-1]; ul > 0) ++ul; else --ul;
                        if(j < board[0].size()-1) if(int &ur = board[i-1][j+1]; ur > 0) ++ur; else --ur;
                    }
                    if(i < board.size()-1){
                        if(int &d = board[i+1][j]; d > 0) ++d; else --d;
                        if(j > 0) if(int &dl = board[i+1][j-1]; dl > 0) ++dl; else --dl;
                        if(j < board[0].size()-1) if(int &dr = board[i+1][j+1]; dr > 0) ++dr; else --dr;
                    }
                    if(j > 0)
                        if(int &left = board[i][j-1]; left > 0) ++left; else --left;
                    if(j < board[0].size()-1)
                        if(int &right = board[i][j+1]; right > 0) ++right; else --right;
                }
            }
        }
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j){
                if(int& cell = board[i][j]; cell < -3)
                    cell = 0;
                else if(cell == -3)
                    cell = 1;
                else if(-3 < cell && cell < 3)
                    cell = 0;
                else if(cell > 4)
                    cell = 0;
                else
                    cell = 1;
            }
        */
    }
};