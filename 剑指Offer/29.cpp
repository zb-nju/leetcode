#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0)
            return {};
        vector<int> ans;
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = cols - 1, up = 0, down = rows - 1;
        while(left <= right && up <= down){
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[up][i]);
            up++;
            for(int i = up; i <= down; i++)
                ans.push_back(matrix[i][right]);
            right--;
            if(up <= down){
                for(int i = right; i >= left; i--)
                    ans.push_back(matrix[down][i]);
                down--;
            }
            if(left <= right){
                for(int i = down; i >= up; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};