/*
 * @Author: your name
 * @Date: 2020-07-14 17:26:51
 * @LastEditTime: 2020-07-26 23:05:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\120.cpp
 */ 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(triangle[n-1]);
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<triangle[i].size();j++){
                int min1=triangle[i][j]+dp[j],min2=triangle[i][j]+dp[j+1];
                dp[j]=min1>min2?min2:min1;
            }
        return dp[0];
    }
};