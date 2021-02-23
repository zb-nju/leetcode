/*
 * @Author: your name
 * @Date: 2020-07-30 00:29:46
 * @LastEditTime: 2020-08-03 16:19:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\1529.cpp
 */ 
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int n=target.size(),i=1,ans=target[0]=='1'?1:0;
        while(i<n){
            ans+=(target[i]!=target[i-1]?1:0);
            i++;
        }
        return ans;
    }
};