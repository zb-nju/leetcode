#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int len = nums.size();
        vector<vector<int>> dp(4, vector<int>(len + 1, 0));
        vector<int>preSum(len + 1, 0);
        for(int i = 1; i <= len; i++)
            preSum[i] = preSum[i - 1] + nums[i - 1];
        for(int i = firstLen; i <= len - secondLen; i++)
            dp[0][i] = std::max(dp[0][i - 1], preSum[i] - preSum[i - firstLen]);
        for(int i = secondLen; i <= len - firstLen; i++)
            dp[1][i] = std::max(dp[1][i - 1], preSum[i] - preSum[i - secondLen]);
        for(int i = len - firstLen; i >= secondLen; i--)
            dp[2][i] = std::max(dp[2][i + 1], preSum[i + firstLen] - preSum[i]);
        for(int i = len - secondLen; i >= firstLen; i--)
            dp[3][i] = std::max(dp[3][i + 1], preSum[i + secondLen] - preSum[i]);
        int res = 0;
        for(int i = 0; i <= len; i++){
            res = std::max(res, dp[0][i] + dp[3][i]);
            res = std::max(res, dp[1][i] + dp[2][i]);
        }
        return res;
    }
};