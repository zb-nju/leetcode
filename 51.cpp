/*
 * @Author: your name
 * @Date: 2020-09-03 10:58:45
 * @LastEditTime: 2020-09-04 14:56:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\51.cpp
 */
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n,string(n,' '));
        for(int i=0;i<n;i++)
            func(cur,0,i,n);
        return ans;
    }

    void func(vector<string> &cur,int x,int y,int n){
        cur[x][y]='Q';
        for(int i=0;i<n;i++){
            if(i!=y)
                cur[x][i]='.';
        }
        if(x==n-1){
            ans.push_back(cur);
            return;
        }
        for(int i=x+1;i<n;i++)
            cur[i][y]='.';
        for(int i=1;i<min(n-x,y+1);i++)
            cur[x+i][y-i]='.';
        for(int i=1;i<min(n-x,n-y);i++)
            cur[x+i][y+i]='.';
        for(int i=0;i<n;i++)
            if(cur[x+1][i]==' ')
                func(cur,x+1,i,n);
        return;
    }

};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                int column = __builtin_ctz(position);
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};