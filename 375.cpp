#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        if(n <= 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i++)
            dp[i][i + 1] = i;
        for(int i = 2; i <= n; i++){
            for(int j = i - 1; j > 0; j--){
                int temp = 2147483647;
                for(int k = j + (i - j) / 2; k < i; k++)
                    temp = min(temp, k + max(dp[j][k - 1], dp[k + 1][i]));
                dp[j][i] = temp;
            }
        }
        return dp[1][n];
    }
};