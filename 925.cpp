/*
 * @Author: zb-nju
 * @Date: 2020-10-21 10:11:17
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-21 10:22:10
 */
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int l=0,r=0;
        while(l<name.size()&&r<typed.size()){
            if(name[l]==typed[r]){
                l++;r++;
            }
            else if(l>0 && name[l-1]==typed[r])
                r++;
            else
                return false;
        }
        if(l<name.size())
            return false;
        l--;
        while(r<typed.size()){
            if(name[l]!=typed[r++])
                return false;
        }
        return true;
    }
};