/*
 * @Author: your name
 * @Date: 2020-08-05 17:13:06
 * @LastEditTime: 2020-08-06 12:02:28
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\14.cpp
 */
#include<iostream>
#include<vector>
#include<string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        bool flag=true;
        int i=0,n=strs.size();
        char c;
        if(n==0)
            return ans;
        while(flag&&i<strs[0].size()){
            c=strs[0][i];
            for(int j=1;j<n;j++)
                if(i>=strs[j].size()||strs[j][i]!=c){
                    flag=false;
                    break;
                }
            if(flag)
                ans+=c;
            i++;
        }
        return ans;
    }
};