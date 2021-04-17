#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = pow(10, n);
        vector<int>ans(max-1,0);
        for(int i=1;i<max;i++){
            ans[i-1] = i;
        }
        return ans;
    }
};