#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        vector<int> dp(prices.size(),0);
        int min=prices[0];
        for(int i=1;i<prices.size();i++){
            dp[i]=max(dp[i-1],prices[i]-min);
            if(prices[i]<min)
                min=prices[i];
        }
        return dp[prices.size()-1];
    }
};