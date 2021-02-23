/*
 * @Author: your name
 * @Date: 2020-08-29 13:44:34
 * @LastEditTime: 2020-08-29 14:15:43
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\214.cpp
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        vector<int>next(n,-1);
        for(int i=1;i<n;i++){
            int j=next[i-1];
            while(j!=-1&&s[j+1]!=s[i])
                j=next[j];
            if(s[j+1]==s[i])
                next[i]=j+1;
        }
        int best=-1;
        for(int i=n-1;i>=0;i--){
            while(best!=-1&&s[best+1]!=s[i])
                best=next[best];
            if(s[best+1]==s[i])
                best++;
        }
        string add=(best==n-1?"":s.substr(best+1,n));
        reverse(add.begin(),add.end());
        return add+s;
    }
};