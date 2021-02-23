/*
 * @Author: your name
 * @Date: 2020-09-01 00:46:46
 * @LastEditTime: 2020-09-01 11:07:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\486.cpp
 */

#include<iostream>
#include<vector>
using namespace std;

// class Solution {
// public:
//     bool PredictTheWinner(vector<int>& nums) {
//         int p1=0,p2=0;
//         return func(nums,p1,p2,0,nums.size()-1,1);
//     }

//     bool func(vector<int>& nums,int& p1,int& p2,int l,int r,bool now){
//         int n=r-l+1;
//         if(n==0)
//             return p1>=p2;
//         int first=nums[l],last=nums[r];
//         if(now){
//             int t1=p1,t2=p1,t3=p2,t4=p2;
//             bool b1,b2;
//             t1+=first;
//             b1=func(nums,t1,t3,l+1,r,!now);
//             t2+=last;
//             b2=func(nums,t2,t4,l,r-1,!now);
//             p1=max(t1,t2);
//             p2=t1>t2?t3:t4;
//             return t1>t2?b1:b2;
//         }
//         else{
//             int t1=p2,t2=p2,t3=p1,t4=p1;
//             bool b1,b2;
//             t1+=first;
//             b1=func(nums,t3,t1,l+1,r,!now);
//             t2+=last;
//             b2=func(nums,t4,t2,l,r-1,!now);
//             p2=max(t1,t2);
//             p1=t1>t2?t3:t4;
//             return t1>t2?b1:b2;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[j]=max(nums[i]-dp[j],nums[j]-dp[j-1]);
            }
        }
        return dp[n-1]>=0;
    }
};