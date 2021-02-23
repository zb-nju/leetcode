/*
 * @Author: your name
 * @Date: 2020-08-29 13:58:37
 * @LastEditTime: 2020-08-29 14:04:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\657.cpp
 */
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int m[2]={0,0};
        for(int i=0;i<moves.size();i++){
            switch (moves[i])
            {
            case 'U':m[0]++;break;
            case 'D':m[0]--;break;
            case 'L':m[1]++;break;
            case 'R':m[1]--;break;
            default:
                break;
            }
        }
        return m[0]==0&&m[1]==0;
    }
};