/*
 * @Author: your name
 * @Date: 2020-09-08 08:38:31
 * @LastEditTime: 2020-09-08 09:07:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\77.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int>now;
    int nn,kk;
    vector<vector<int>> combine(int n, int k) {
        nn=n;kk=k;
        func(0,0);
        return ans;
    }
    void func(int know,int pnow){
        if(kk==know){
            ans.push_back(now);
            return;
        }
        if((nn-pnow)<(kk-know))
            return;
        now.push_back(pnow+1);
        func(know+1,pnow+1);
        now.pop_back();
        func(know,pnow+1);
        return;
    }
};