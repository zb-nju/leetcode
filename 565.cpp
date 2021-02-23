/*
 * @Author: your name
 * @Date: 2020-07-07 15:39:11
 * @LastEditTime: 2020-07-07 15:39:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\565.cpp
 */ 
#include<vector>

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> visit(nums.size(),false);
        int max=0,temp=0;
        for(int i=0;i<nums.size();i++)
            if(!visit[i]){
                temp = 0;
                while(!visit[i]){
                    visit[i]=true;
                    i = nums[i];
                    temp++;
                }
                if(temp>max)
                    max = temp;
            }
        return max;
    }
};