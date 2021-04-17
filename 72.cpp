#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++)
            dp[0][i] = i;
        for(int i = 0; i < n; i++)
            dp[i][0] = i;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(word1[i] == word2[j])
                    dp[i][j] = ::min(::min(dp[i-1][j], dp[i][j-1]) + 1, dp[i-1][j-1]);
                else
                    dp[i][j] = ::min(::min(dp[i-1][j], dp[i][j-1]) + 1, dp[i-1][j-1] + 1);
            }
        }
        return dp[i - 1][j - 1];
    }
};