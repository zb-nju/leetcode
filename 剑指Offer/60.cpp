#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<int> dp(6*n+1, 0);
        for(int i = 1; i <= 6; i++)
            dp[i] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 6 * i; j >= i; j--){
                dp[j] = 0;
                for(int k = 1; k <= 6; k++){
                    if(j - k < i - 1)
                        break;
                    dp[j] += dp[j - k];
                }
            }
        }
        int sum = pow(6, n);
        vector<double> ans;
        for(int i = n; i <= 6*n; i++){
            ans.push_back(double(dp[i])/sum);
        }
        return ans;
    }
};