#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int a = nums.size(), b = nums[0].size(), n = a * b;
        if(n != r * c)
            return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i=0;i<n;i++)
            ans[i/c][i%c] = nums[i/b][i%b];
        return ans;
    }
};