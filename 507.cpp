/*
 * @Author: your name
 * @Date: 2020-07-29 23:54:54
 * @LastEditTime: 2020-07-29 23:54:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\507.cpp
 */ 
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<2)
            return false;
        int sq=sqrt(num),t=1;
        for(int i=2;i<=sq;i++){
            if(num%i==0){
                t+=i;
                t+=num/i;
            }
        }
        return t==num;
    }
};