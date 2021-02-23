/*
 * @Author: your name
 * @Date: 2020-08-19 20:17:53
 * @LastEditTime: 2020-08-19 22:08:16
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\345.cpp
 */
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int l=0,r=s.size()-1,n=s.size();
        char c;
        while(l<r){
            while(l<n&&s[l]!='a'&&s[l]!='e'&&s[l]!='i'&&s[l]!='o'&&s[l]!='u'&&s[l]!='A'&&s[l]!='E'&&s[l]!='I'&&s[l]!='O'&&s[l]!='U') l++;
            while(r>=0&&s[r]!='a'&&s[r]!='e'&&s[r]!='i'&&s[r]!='o'&&s[r]!='u'&&s[r]!='A'&&s[r]!='E'&&s[r]!='I'&&s[r]!='O'&&s[r]!='U') r--;
            if(l<r){
                c=s[l];
                s[l]=s[r];
                s[r]=c;
                l++;r--;
            }
        }
        return s;
    }
};