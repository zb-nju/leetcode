/*
 * @Author: your name
 * @Date: 2020-07-12 23:51:33
 * @LastEditTime: 2020-07-13 00:30:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\647.cpp
 */ 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// class Solution {
// public:
//     int func(string& s,int l,int r){
//         while(l<=r)
//         {
//             if(s[l]!=s[r])
//                 return 0;
//             l++;r--;
//         }
//         return 1;
//     }

//     int countSubstrings(string s) {
//         int ans=s.size();
//         int n=s.size();
//         for(int i=0;i<n;i++)
//             for(int j=i+1;j<n;j++)
//                 if(s[i]==s[j])
//                     ans+=func(s,i,j);
//         return ans;
//     }
// };

class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<2*n-1;i++){
            int l=i/2,r=l+i%2;
            while(l>=0&&r<n&&s[l]==s[r]){
                ans++;l--;r++;
            }
        }
        return ans;
    }
};

int main(){
    string a="aaa";
    Solution s;
    cout<<s.countSubstrings(a);
    return 0;
}