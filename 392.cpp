/*
 * @Author: your name
 * @Date: 2020-07-27 14:06:13
 * @LastEditTime: 2020-07-27 14:06:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\392.cpp
 */ 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size(),i=0,j=0;
        if(n==0)
            return true;
        while(j<m){
            if(s[i]==t[j]){
                i++;
                if(i>=n)
                    return true;
            }
            j++;
        }
        return false;
    }
};