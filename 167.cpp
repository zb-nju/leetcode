/*
 * @Author: your name
 * @Date: 2020-02-17 13:23:45
 * @LastEditTime: 2020-08-31 10:27:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\167.cpp
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        vector<int>ans;
        for(int i=0,j=len-1;i!=j)
        {
            int t=numbers[i]+numbers[j];
            if(t>target)
                j--;
            else if(t<target)
                i++;
            else
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};