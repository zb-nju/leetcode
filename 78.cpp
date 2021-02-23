/*
 * @Author: your name
 * @Date: 2020-09-20 10:05:49
 * @LastEditTime: 2020-09-21 14:53:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\78.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> now;

    vector<vector<int>> subsets(vector<int>& nums) {
        func(nums,0);
        return ans;
    }

    void func(vector<int>& nums,int p){
        if(p==nums.size()){
            ans.push_back(now);
            return;
        }
        now.push_back(nums[p]);
        func(nums,p+1);
        now.pop_back();
        func(nums,p+1);
    }
};