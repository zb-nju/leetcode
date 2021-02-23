/*
 * @Author: your name
 * @Date: 2020-07-30 00:05:55
 * @LastEditTime: 2020-07-30 00:05:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\343.cpp
 */ 
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int t=n/3,m=n%3,ans;
        switch (m)
        {
            case 0:ans=pow(3,t);break;
            case 1:ans=pow(3,t-1)*4;break;
            case 2:ans=pow(3,t)*2;break;
        }
        return ans;
    }
};