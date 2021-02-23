#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int,int>> spaces;

    void dfs(vector<vector<char>>& board,int pos){
        if(pos==spaces.size()){
            valid = true;
            return;
        }
        int i=spaces[pos].first,j=spaces[pos].second;
        for(int k=0;k<9&&!valid;k++){
            if(!line[i][k]&&!column[j][k]&&!block[i/3][j/3][k]){
                line[i][k] = column[j][k] = block[i/3][j/3][k] = true;
                board[i][j] = k+'0'+1;
                dfs(board,pos+1);
                line[i][k] = column[j][k] = block[i/3][j/3][k] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line,false,sizeof(line));
        memset(column,false,sizeof(column));
        memset(block,false,sizeof(block));
        valid = false;

        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    spaces.emplace_back(i,j);
                else{
                    int d = board[i][j]-'0'-1;
                    line[i][d]=column[j][d]=block[i/3][j/3][d]=true;
                }
            }
        dfs(board,0);
    }
};