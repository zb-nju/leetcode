/*
 * @Author: zb-nju
 * @Date: 2020-10-17 23:35:37
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-17 23:41:47
 */
#include<iostream>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        solve(ans, n, 0, 0, 0, 0);
        return solutions.size();
    }

    void solve(int&ans, int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            ans++;
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                int column = __builtin_ctz(position);
                solve(solutions, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
            }
        }
    }
};