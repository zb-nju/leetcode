/*
 * @Author: your name
 * @Date: 2020-08-03 16:02:40
 * @LastEditTime: 2020-08-03 16:18:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\415.cpp
 */ 
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n1=num1.size(),n2=num2.size(),i=0,c=0,t;
        string ans;
        while(i<n1&&i<n2){
            t=num1[i]+num2[i]-2*'0'+c;
            c=t>=10?1:0;
            num1[i]=t+'0'-10*c;
            i++;
        }
        while(i<n1){
            t=num1[i]+c-'0';
            c=t>=10?1:0;
            num1[i]=t+'0'-10*c;
            i++;
        }
        while(i<n2){
            t=num2[i]+c-'0';
            c=t>=10?1:0;
            num1+=(t+'0'-10*c);
            i++;
        }
        if(c)
            num1+='1';
        reverse(num1.begin(),num1.end());
        return num1;
    }
};