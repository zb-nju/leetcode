#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int rows, cols, len;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k])
            return false;
        if(k == len-1)
            return true;
        board[i][j] = '\0';
        for(int x = 0; x < 4; x++){
            if(dfs(board, word, i+di[x], j+dj[x], k+1))
                return true;
        }
        board[i][j] = word[k];
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        len = word.size();
        if(rows == 0)
            return len == 0 ? true : false;
        cols = board[0].size();
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        return false;
    }
};