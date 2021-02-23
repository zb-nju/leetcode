/*
 * @Author: your name
 * @Date: 2020-08-10 15:12:43
 * @LastEditTime: 2020-08-10 15:20:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\696.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size()<2)
            return 0;
        int t=0,ans=0,last=0,n=s.size();
        for(int i=0;i<n;){
            char c=s[i];
            while(i<n&&s[i]==c){
                i++;
                t++;
            }
            ans+=last<t?last:t;
            last=t;
            t=0;
        }
        return ans;
    }
};