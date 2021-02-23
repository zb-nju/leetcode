/*
 * @Author: zb-nju
 * @Date: 2020-10-08 10:12:58
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-08 10:20:12
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0,r=s.size()-1;
        char t;
        while(l<r){
            t=s[l];
            s[l]=s[r];
            s[r]=t;
        }
        return;
    }
};