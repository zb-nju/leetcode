/*
 * @Author: your name
 * @Date: 2020-08-22 11:26:09
 * @LastEditTime: 2020-08-22 11:46:03
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\679.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> l;
        for(int i=0;i<4;i++)
            l.push_back(nums[i]);
        return func(l);
    }

    bool func(vector<double>&list){
        if(list.size()==0)
            return false;
        if(list.size()==1)
            return fabs(list[0]-24)<1e-6;
        int n=list.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    vector<double> l;
                    for(int k=0;k<n;k++){
                        if(k!=i&&k!=j)
                            l.push_back(list[k]);
                    }
                    for(int k=0;k<4;k++){
                        if(k<2&&i>j)
                            continue;
                        switch (k)
                        {
                        case 0:l.push_back(list[i]+list[j]);break;
                        case 1:l.push_back(list[i]*list[j]);break;
                        case 2:l.push_back(list[i]-list[j]);break;
                        case 3:l.push_back(list[i]/list[j]);break;
                        default:
                            break;
                        }
                        if(func(l))
                            return true;
                        l.pop_back();
                    }
                }
            }
        }
        return false;
    }
};