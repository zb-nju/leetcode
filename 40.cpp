/*
 * @Author: your name
 * @Date: 2020-09-10 09:18:25
 * @LastEditTime: 2020-09-10 09:38:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\40.cpp
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>t;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0,0);
        return ans;
    }
    void func(vector<int>&candidates,int target,int now,int begin){
        if(now==target){
            ans.push_back(t);
            return;
        }
        else
        {
            int last = 0;
            for(int i=begin;i<candidates.size();i++){
                if(candidates[i]!=last&&now+candidates[i]<=target){
                    last = candidates[i];
                    t.push_back(candidates[i]);
                    func(candidates,target,now+candidates[i],i+1);
                    t.pop_back();
                }
            }
        }
    }
};