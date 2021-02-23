/*
 * @Author: your name
 * @Date: 2020-09-18 07:53:53
 * @LastEditTime: 2020-09-18 11:29:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\47.cpp
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>now;
    int n;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<bool>visit(n,false);
        sort(nums.begin(),nums.end());
        dfs(nums,visit);
        return ans;
    }

    void dfs(vector<int>&nums,vector<bool>&visit){
        if(now.size()==nums.size()){
            ans.push_back(now);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]&&!visit[i-1])
                continue;
            if(!visit[i]){
                visit[i]=true;
                now.push_back(nums[i]);
                dfs(nums,visit);
                now.pop_back();
                visit[i]=false;
            }
        }
    }
};