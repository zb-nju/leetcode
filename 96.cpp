/*
 * @Author: your name
 * @Date: 2020-07-15 17:55:49
 * @LastEditTime: 2020-07-15 17:55:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\96.cpp
 */ 
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
            for(int j=0;j<i;j++)
                dp[i]+=dp[j]*dp[i-j-1];
        return dp[n];
    }
};

int main