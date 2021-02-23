/*
 * @Author: your name
 * @Date: 2020-07-04 16:26:53
 * @LastEditTime: 2020-07-04 16:52:33
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\240.cpp
 */ 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0)
            return false;
        int n=matrix[0].size();
        int i=m-1,j=0;
        while(i>0&&j<n)
        {
            if(matrix[i][j]>target)
                j++;
            else if(matrix[i][j]<target)
                i--;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>>matrix;
    Solution s;
    for(int i=0;i<5;i++)
    {
        vector<int>t;
        for(int j=0;j<5;j++)
            t.push_back(5*i+j);
        matrix.push_back(t);
    }
    s.searchMatrix(matrix,5);
}