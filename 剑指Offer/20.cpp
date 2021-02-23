/*
 * @Author: your name
 * @Date: 2020-09-02 09:58:26
 * @LastEditTime: 2020-09-02 10:46:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\剑指Offer\20.cpp
 */
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool dot=false,e=false,num=false,space=false,first=false;
        int n=s.size();
        if(n==0)
            return false;
        for(int i=0;i<n;i++){
            switch (s[i])
            {
            case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
                num=true;
                first=true;
                if(space)
                    return false;
                break;

            case 'e':case 'E':
                if(!num||e||space)
                    return false;
                else{
                    num=false;
                    e=true;
                    dot=true;
                }
                break;

            case '.':
                if(n<=1||dot||space)
                    return false;
                else{
                    first=true;
                    dot=true;
                    //num=false;
                }
                break;

            case '+':case '-':
                if(!first&&n>0){
                    first=true;
                    break;
                }
                else if(s[i-1]=='e'||s[i-1]=='E')
                    num=false;
                else
                    return false;
                break;
            case ' ':
                if(first)
                    space = true;
                break;
            default:
                return false;
                break;
            }
        }
        return num;
    }
};