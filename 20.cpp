/*
 * @Author: your name
 * @Date: 2020-08-14 08:01:27
 * @LastEditTime: 2020-08-16 08:21:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\20.cpp
 */
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(int i=0;i<s.size();i++){
            switch (s[i])
            {
            case '(':case '[':case '{':
                mystack.push(s[i]);
                break;
            case ')':
                if(!mystack.empty()){
                    if(mystack.top()!='(')
                        return false;
                    mystack.pop();
                }
                else
                    return false;
                break;
            case ']':
                if(!mystack.empty()){
                    if(mystack.top()!='[')
                        return false;
                    mystack.pop();
                }
                else
                    return false;
                break;
            case '}':
                if(!mystack.empty()){
                    if(mystack.top()!='{')
                        return false;
                    mystack.pop();
                }
                else
                    return false;
                break;
            default:
                return false;
                break;
            }
        }
        return mystack.empty();
    }
};