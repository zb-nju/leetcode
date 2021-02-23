/*
 * @Author: your name
 * @Date: 2020-08-05 17:00:34
 * @LastEditTime: 2020-08-05 17:12:56
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\13.cpp
 */
#include<iostream>
#include<string>
using namespace std;

inline int atoi(char c){
    int ans;
    switch (c)
    {
    case 'I':ans=1;break;
    case 'V':ans=5;break;
    case 'X':ans=10;break;
    case 'L':ans=50;break;
    case 'C':ans=100;break;
    case 'D':ans=500;break;
    case 'M':ans=1000;break;
    default:
        ans=0;
        break;
    }
    return ans;
}

class Solution {
public:
    int romanToInt(string s) {
        int ans=0,now=0,next=atoi(s[0]);
        for(int i=0;i<s.size()-1;i++){
            now=next;
            next=atoi(s[i+1]);
            if(now<next)
                ans-=now;
            else
                ans+=now;
        }
        return ans+next;
    }
};