#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int>dp(n+1, 1);
        dp[1]=dp[2]=1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], max(j*(i-j), j * dp[i-j]));
            }
        }
        return dp[n];
    }
};

class Solution{
public:
    int cuttingRope(int n) {
        if(n <= 3) return n-1;
        else{
            int ans = 1;
            while(n>=3){
                if(n == 4){
                    ans *= 4;
                    n -= 4;
                    break;
                }else{
                    ans *= 3;
                    n -= 3;
                }
            }
            if(n)
                ans*=n;
            return ans;
        }
    }
};