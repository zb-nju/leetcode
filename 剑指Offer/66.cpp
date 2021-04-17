#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if(n == 0) return {};
        vector<int> ans(n, 1);
        for(int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * a[i - 1];
        int temp = 1;
        for(int i = n - 2; i >= 0; i--){
            temp *= a[i + 1];
            ans[i] *= temp;
        }
        return ans;
    }
};