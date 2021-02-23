/*
 * @Author: zb-nju
 * @Date: 2020-10-19 16:49:27
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-19 16:58:40
 */
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s,t;
        for(int i=0;i<S.size();i++){
            if(S[i]=='#'){
                if(!s.empty())
                    s.pop();
            }
            else{
                s.emplace(S[i]);
            }
        }
        for(int i=0;i<T.size();i++){
            if(T[i]=='#'){
                if(!t.empty())
                    t.pop();
            }
            else{
                t.emplace(T[i]);
            }
        }
        if(s.size()!=t.size())
            return false;
        while(!s.empty()){
            if(s.top()!=t.top())
                return false;
            s.pop();t.pop();
        }
        return true;
    }
};

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++, i--;
                } else if (skipS > 0) {
                    skipS--, i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++, j--;
                } else if (skipT > 0) {
                    skipT--, j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            i--, j--;
        }
        return true;
    }
};
