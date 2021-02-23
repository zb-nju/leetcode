/*
 * @Author: your name
 * @Date: 2020-08-03 19:05:35
 * @LastEditTime: 2020-08-04 10:24:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\11.cpp
 */
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,max=0,t;
        while(i<j){
            if(height[i]>height[j]){
                t=height[j]*(j-i);
                if(t>max)
                    max=t;
                else
                    j--;
            }
            else{
                t=height[i]*(j-i);
                if(t>max)
                    max=t;
                else
                    i++;
            }
        }
        return max;
    }
};