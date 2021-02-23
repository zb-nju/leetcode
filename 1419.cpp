/*
 * @Author: your name
 * @Date: 2020-07-09 21:12:34
 * @LastEditTime: 2020-07-10 08:28:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\1419.cpp
 */ 
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ans=1,temp=0,c=0,r=0,o=0,a=0,k=0;
        for(int i=0;i<croakOfFrogs.size();i++)
        {
            switch (croakOfFrogs[i])
            {
                case 'c':
                    c++;break;
                case 'r':
                    r++;break;
                case 'o':
                    o++;break;
                case 'a':
                    a++;break;
                case 'k':
                    k++;
                    temp = c-k+1;
                    ans = temp>ans?temp:ans;
                    break;
                default:
                    return -1;
                    break;
            }
            if(!(c>=r&&r>=o&&o>=a&&a>=k))
                return -1;
        }
        if(c==r&&r==o&&o==a&&a==k)
            return ans;
        else
            return -1;
    }
};

int main(){
    string t="aoocrrackk";
    Solution s;
    cout<<s.minNumberOfFrogs(t);
    return 0;
}