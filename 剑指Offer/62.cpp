#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        int dp = 0;
        for(int i = 1; i <= n; i++)
            dp = (dp + m) % i;
        return dp;
    }
};