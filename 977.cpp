/*
 * @Author: zb-nju
 * @Date: 2020-10-16 10:38:27
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-10-16 10:47:56
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l=0,r=A.size()-1,i=r;
        vector<int>ans(A.size());
        for(int j=0;j<A.size();j++)
            A[j] *= A[j];
        while(l<=r)
            ans[i--]=A[l]<A[r]?A[r--]:A[l++];
        return ans;
    }
};