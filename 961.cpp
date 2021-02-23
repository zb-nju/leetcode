/*
 * @Author: your name
 * @Date: 2020-07-07 15:58:17
 * @LastEditTime: 2020-07-07 17:12:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\961.cpp
 */ 
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int ans = A[0],t=1,n=A.size();
        for(int i=1;i<n-1;i++){
            if(!t)
                ans=A[i];
            if(ans==A[i])
                t++;
            else
                t--;
        }
        if(t>1)
            return ans;
        t=0;
        for(int i=0;i<n;i++)
            if(ans==A[i])
                t++;
        if(t==n/2)
            return ans;
        else
            return A[n-1];
    }
};