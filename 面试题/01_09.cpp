/*
 * @Author: your name
 * @Date: 2020-08-21 10:32:50
 * @LastEditTime: 2020-08-22 11:25:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\面试题\01_09.cpp
 */
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;
        return (s1+s2).find(s1)!=string::npos;
    }
};